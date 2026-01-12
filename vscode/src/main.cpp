#include <Arduino.h>
#include <M5Unified.h>
#include <Wire.h>

#include <Unit_Sonic.h>
#include "M5UnitPbHub.h"
#include "ClosedCube_TCA9548A.h"

#include <EEPROM.h>

#include "driver/gpio.h"

#include "ui/ui.h"
#include "ui/eez-flow.h"
#include "ui/screens.h"
#include "ui/vars.h"

#include "my_lv_common_code.h"
#include "my_unit_control.h"
#include "main.h"

ModbusRTU mb;

HardwareSerial &ModbusRTU_Serial = Serial2;

SONIC_I2C us_sensor;
M5UnitPbHub pbhub;
ClosedCube::Wired::TCA9548A pahub;
#define PaHub_I2C_ADDRESS (0x70)

lv_chart_series_t *ser1;
lv_chart_series_t *ser2;
lv_chart_series_t *ser3;
lv_chart_series_t *ser4;
lv_chart_series_t *ser5;

int32_t *ser1_y_points;
int32_t *ser2_y_points;
int32_t *ser3_y_points;
int32_t *ser4_y_points;
int32_t *ser5_y_points;

void chart_auto_scale(lv_obj_t *chart, lv_chart_series_t *ser)
{
  int32_t *y = lv_chart_get_series_y_array(chart, ser);
  uint32_t count = lv_chart_get_point_count(chart);

  int32_t min_v = INT32_MAX;
  int32_t max_v = INT32_MIN;

  for (uint32_t i = 0; i < count; i++)
  {
    if (y[i] < min_v)
      min_v = y[i];
    if (y[i] > max_v)
      max_v = y[i];
  }

  int32_t margin = (max_v - min_v) / 10;
  if (margin < 10)
    margin = 10;

  lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y,
                     min_v - margin,
                     max_v + margin);
}

void setup_MODBUS_Slave(uint8_t slaveid)
{
  ModbusRTU_Serial.begin(MODBUS_BAUD, SERIAL_8E1, MODBUS_RX_PIN, MODBUS_TX_PIN);
  mb.begin(&ModbusRTU_Serial, MODBUS_DE_PIN, true);
  mb.slave(slaveid);
  mb.addHreg(0, 0, REG_COUNT);
  mb.setInterFrameTime(200 * 1000);

  // Clear loop back from RS485
  // attachInterrupt(digitalPinToInterrupt(MODBUS_DE_PIN), on_MODBUS_DE_PIN_fallingChange, FALLING);
}

void setup_LVGL_chart_set(lv_obj_t *target_chart, lv_chart_series_t **target_ser, int32_t **target_ser_y_points)
{
  lv_chart_set_type(target_chart, LV_CHART_TYPE_LINE);
  lv_chart_set_point_count(target_chart, 30);
  lv_chart_set_update_mode(target_chart, LV_CHART_UPDATE_MODE_SHIFT);
  *target_ser = lv_chart_add_series(target_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
  //*target_ser_y_points = lv_chart_get_series_y_array(target_chart, *target_ser);
}

void setup_LVGL()
{
  my_lv_device_initialize(M5.Display);
  lv_init();
  ui_init();

  setup_LVGL_chart_set(objects.chart_1, &ser1, &ser1_y_points);
  setup_LVGL_chart_set(objects.chart_2, &ser2, &ser2_y_points);
  setup_LVGL_chart_set(objects.chart_3, &ser3, &ser3_y_points);
  setup_LVGL_chart_set(objects.chart_4, &ser4, &ser4_y_points);
  setup_LVGL_chart_set(objects.chart_5, &ser5, &ser5_y_points);

  setup_LVGL_chart_range();

  String LVGL_Arduino = "LVGL information : ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  M5_LOGI("%s", LVGL_Arduino);
}

void setup_LVGL_chart_range()
{
  // chart 1
  lv_chart_set_range(objects.chart_1, LV_CHART_AXIS_PRIMARY_Y,
                     ResBuff.chart_min_1, ResBuff.chart_max_1);

  // chart 2
  lv_chart_set_range(objects.chart_2, LV_CHART_AXIS_PRIMARY_Y,
                     ResBuff.chart_min_2, ResBuff.chart_max_2);

  // chart 3
  lv_chart_set_range(objects.chart_3, LV_CHART_AXIS_PRIMARY_Y,
                     ResBuff.chart_min_3, ResBuff.chart_max_3);

  // chart 4
  lv_chart_set_range(objects.chart_4, LV_CHART_AXIS_PRIMARY_Y,
                     ResBuff.chart_min_4, ResBuff.chart_max_4);

  // chart 5
  lv_chart_set_range(objects.chart_5, LV_CHART_AXIS_PRIMARY_Y,
                     ResBuff.chart_min_5, ResBuff.chart_max_5);
}

void setup()
{
  auto cfg = M5.config();
  cfg.internal_imu = false;
  M5.begin(cfg);
  M5.Log.setLogLevel(m5::log_target_serial, ESP_LOG_VERBOSE);

  loadEEPROM();

  setup_LVGL();
  setup_MODBUS_Slave(SLAVE_ID);

  update_registry_from_struct();
  update_device_from_struct();

  Wire.begin(PortA_SDA, PortA_SCL);
  Wire.setClock(100000);
  us_sensor.begin(&Wire, 0x57, PortA_SDA, PortA_SCL, 100 * 1000U);
  pbhub.begin(&Wire, UNIT_PBHUB_I2C_ADDR, PortA_SDA, PortA_SCL, 100 * 1000U);
  pahub.address(PaHub_I2C_ADDRESS);
}

uint32_t interval_UI = 33;
uint64_t lastMillis_UI = 0;

uint32_t interval_REG = 33;
uint64_t lastMillis_REG = 0;

uint32_t interval_US = 1000;
uint64_t lastMillis_US = 0;

uint32_t interval_PBH = 1000;
uint64_t lastMillis_PBH = 0;

void loop()
{
  M5.update();
  unsigned long Millis = millis();

  // MODBUS update
  if (Millis - lastMillis_REG > interval_REG)
  {
    mb.task();
    update_struct_from_registry();
    update_device_from_struct();
    lastMillis_REG = Millis;
  }

  // LVGL update
  if (Millis - lastMillis_UI > interval_UI)
  {
    lv_task_handler();
    ui_tick();
    update_struct_from_device();
    update_registry_from_struct();
    lastMillis_UI = Millis;

    if (interval_US != ResBuff.unit_int_sv_1)
    {
      interval_US = ResBuff.unit_int_sv_1;
    }

    if (interval_PBH != ResBuff.unit_int_sv_2)
    {
      interval_PBH = ResBuff.unit_int_sv_2;
    }
  }

  // Units update
  if (Millis - lastMillis_US > interval_US)
  {
    int32_t Distance = (int32_t)(us_sensor.getDistance() * 10.0f);
    lastMillis_US = Millis;
    set_var_unit_pv_1(Distance);
    lv_chart_set_next_value(objects.chart_1, ser1, Distance);
    //chart_auto_scale(objects.chart_1, ser1);
  }

  if (Millis - lastMillis_PBH > interval_PBH)
  {
    int32_t AD0 = (int32_t)(pbhub.analogRead(0));
    lastMillis_PBH = Millis;
    set_var_unit_pv_2(AD0);
    lv_chart_set_next_value(objects.chart_2, ser2, AD0);
    //chart_auto_scale(objects.chart_2, ser2);
  }

  yield();
}
