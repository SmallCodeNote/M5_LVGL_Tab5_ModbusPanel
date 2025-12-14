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
#include "main.h"

ModbusRTU mb;
ModbusRegisterValues ResBuff;
ModbusRegisterValues ResPrev;
HardwareSerial &ModbusRTU_Serial = Serial2;



SONIC_I2C us_sensor;
M5UnitPbHub pbhub;
ClosedCube::Wired::TCA9548A pahub;
#define PaHub_I2C_ADDRESS (0x70)


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

template <typename T>
void update_and_call(T &current, T &previous, T newValue, void (*callback)(T))
{
  current = newValue;
  if (current != previous)
  {
    callback(current);
    previous = current;
  }
}
void update_MODBUS_Registry()
{
  update_and_call(ResBuff.lock_flag, ResPrev.lock_flag, mb.Hreg(lock_flag) > 0, set_var_lock_flag);
  update_and_call(ResBuff.run_flag, ResPrev.run_flag, mb.Hreg(run_flag) > 0, set_var_run_flag);
  update_and_call(ResBuff.display_pv_1, ResPrev.display_pv_1, (int32_t)mb.Hreg(display_pv_1) , set_var_display_pv_1);
  update_and_call(ResBuff.display_pv_2, ResPrev.display_pv_2, (int32_t)mb.Hreg(display_pv_2) , set_var_display_pv_2);
  update_and_call(ResBuff.display_pv_3, ResPrev.display_pv_3, (int32_t)mb.Hreg(display_pv_3) , set_var_display_pv_3);
  update_and_call(ResBuff.display_pv_4, ResPrev.display_pv_4, (int32_t)mb.Hreg(display_pv_4) , set_var_display_pv_4);
  update_and_call(ResBuff.display_pv_5, ResPrev.display_pv_5, (int32_t)mb.Hreg(display_pv_5) , set_var_display_pv_5);
  

}

void setup_LVGL()
{
  my_lv_device_initialize(M5.Display);
  lv_init();
  ui_init();

  String LVGL_Arduino = "LVGL information : ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  M5_LOGI("%s", LVGL_Arduino);
}

void setup()
{
  auto cfg = M5.config();
  cfg.internal_imu = false;
  M5.begin(cfg);
  M5.Log.setLogLevel(m5::log_target_serial, ESP_LOG_VERBOSE);

  setup_LVGL();
  setup_MODBUS_Slave(SLAVE_ID);

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

  if (Millis - lastMillis_UI > interval_UI)
  {
    lv_task_handler();
    ui_tick();
    lastMillis_UI = Millis;
  }

  if (Millis - lastMillis_REG > interval_REG)
  {
    mb.task();
    update_MODBUS_Registry();
    lastMillis_REG = Millis;
  }

  if (Millis - lastMillis_US > interval_US)
  {
    int32_t Distance = (int32_t)(us_sensor.getDistance() * 10.0f);
    lastMillis_US = Millis;
    set_var_unit_pv_1(Distance);
  }

    if (Millis - lastMillis_PBH > interval_PBH)
  {
    int32_t AD0 = (int32_t)(pbhub.analogRead(0));
    lastMillis_PBH = Millis;
    set_var_unit_pv_2(AD0);
  }

  
  yield();
}
