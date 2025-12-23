#include <Arduino.h>
#include <M5Unified.h>
#include <Wire.h>
#include <Unit_Sonic.h>
#include <VL53L0X.h>
#include <VL53L1X.h>
#include <EEPROM.h>

#include "my_unit_control.h"
#include "main.h"

ModbusRegisterValues ResBuff;
ModbusRegisterValues ResPrev;


void saveEEPROM(ModbusRegisterValues deviceParam)
{
    EEPROM.begin(EEPROM_SIZE);
    int addr = EEPROM_ADDR;

    EEPROM.put(addr, EEPROM_ID_DPRM);
    addr += sizeof(EEPROM_ID_DPRM);

    EEPROM.put(addr, EEPROM_VERSION_DPRM);
    addr += sizeof(EEPROM_VERSION_DPRM);

    EEPROM.put(addr, deviceParam);

    EEPROM.commit();
    EEPROM.end();

    Serial.println("EEPROM save complete.");
    Serial.printf("ID: 0x%08X, Version: %d\n", EEPROM_ID_DPRM, EEPROM_VERSION_DPRM);

    // flag
    Serial.printf("lock_flag: %d\n", deviceParam.lock_flag);
    Serial.printf("run_flag: %d\n", deviceParam.run_flag);

    // display
    Serial.printf("display_pv_1: %d\n", deviceParam.display_pv_1);
    Serial.printf("display_pv_2: %d\n", deviceParam.display_pv_2);
    Serial.printf("display_pv_3: %d\n", deviceParam.display_pv_3);
    Serial.printf("display_pv_4: %d\n", deviceParam.display_pv_4);
    Serial.printf("display_pv_5: %d\n", deviceParam.display_pv_5);

    // progress
    Serial.printf("run_progress_max: %d\n", deviceParam.run_progress_max);
    Serial.printf("run_progress: %d\n", deviceParam.run_progress);

    // run sv
    Serial.printf("run_sv_1: %d\n", deviceParam.run_sv_1);
    Serial.printf("run_sv_2: %d\n", deviceParam.run_sv_2);
    Serial.printf("run_sv_3: %d\n", deviceParam.run_sv_3);
    Serial.printf("run_sv_4: %d\n", deviceParam.run_sv_4);
    Serial.printf("run_sv_5: %d\n", deviceParam.run_sv_5);
    Serial.printf("run_sv_select: %d\n", deviceParam.run_sv_select);
    Serial.printf("run_sv_status: %d\n", deviceParam.run_sv_status);

    // unit interval
    Serial.printf("unit_int_sv_1: %d\n", deviceParam.unit_int_sv_1);
    Serial.printf("unit_int_sv_2: %d\n", deviceParam.unit_int_sv_2);
    Serial.printf("unit_int_sv_3: %d\n", deviceParam.unit_int_sv_3);
    Serial.printf("unit_int_sv_4: %d\n", deviceParam.unit_int_sv_4);
    Serial.printf("unit_int_sv_5: %d\n", deviceParam.unit_int_sv_5);

    // unit pv
    Serial.printf("unit_pv_1: %d\n", deviceParam.unit_pv_1);
    Serial.printf("unit_pv_2: %d\n", deviceParam.unit_pv_2);
    Serial.printf("unit_pv_3: %d\n", deviceParam.unit_pv_3);
    Serial.printf("unit_pv_4: %d\n", deviceParam.unit_pv_4);
    Serial.printf("unit_pv_5: %d\n", deviceParam.unit_pv_5);

    // chart max
    Serial.printf("chart_max_1: %d\n", deviceParam.chart_max_1);
    Serial.printf("chart_max_2: %d\n", deviceParam.chart_max_2);
    Serial.printf("chart_max_3: %d\n", deviceParam.chart_max_3);
    Serial.printf("chart_max_4: %d\n", deviceParam.chart_max_4);
    Serial.printf("chart_max_5: %d\n", deviceParam.chart_max_5);

    // chart min
    Serial.printf("chart_min_1: %d\n", deviceParam.chart_min_1);
    Serial.printf("chart_min_2: %d\n", deviceParam.chart_min_2);
    Serial.printf("chart_min_3: %d\n", deviceParam.chart_min_3);
    Serial.printf("chart_min_4: %d\n", deviceParam.chart_min_4);
    Serial.printf("chart_min_5: %d\n", deviceParam.chart_min_5);
}

void saveEEPROM()
{
    saveEEPROM(ResBuff);
}



void loadEEPROM(ModbusRegisterValues &deviceParam)
{
    EEPROM.begin(EEPROM_SIZE);

    int addr = EEPROM_ADDR;

    uint32_t id;
    uint8_t version;

    EEPROM.get(addr, id);
    addr += sizeof(id);

    EEPROM.get(addr, version);
    addr += sizeof(version);

    if (id == EEPROM_ID_DPRM && version == EEPROM_VERSION_DPRM)
    {
        EEPROM.get(addr, deviceParam);

        Serial.println("EEPROM load complete.");
        Serial.printf("ID: 0x%08X, Version: %d\n", id, version);

        // flag
        Serial.printf("lock_flag: %d\n", deviceParam.lock_flag);
        Serial.printf("run_flag: %d\n", deviceParam.run_flag);

        // display
        Serial.printf("display_pv_1: %d\n", deviceParam.display_pv_1);
        Serial.printf("display_pv_2: %d\n", deviceParam.display_pv_2);
        Serial.printf("display_pv_3: %d\n", deviceParam.display_pv_3);
        Serial.printf("display_pv_4: %d\n", deviceParam.display_pv_4);
        Serial.printf("display_pv_5: %d\n", deviceParam.display_pv_5);

        // progress
        Serial.printf("run_progress_max: %d\n", deviceParam.run_progress_max);
        Serial.printf("run_progress: %d\n", deviceParam.run_progress);

        // run sv
        Serial.printf("run_sv_1: %d\n", deviceParam.run_sv_1);
        Serial.printf("run_sv_2: %d\n", deviceParam.run_sv_2);
        Serial.printf("run_sv_3: %d\n", deviceParam.run_sv_3);
        Serial.printf("run_sv_4: %d\n", deviceParam.run_sv_4);
        Serial.printf("run_sv_5: %d\n", deviceParam.run_sv_5);
        Serial.printf("run_sv_select: %d\n", deviceParam.run_sv_select);
        Serial.printf("run_sv_status: %d\n", deviceParam.run_sv_status);

        // unit interval
        Serial.printf("unit_int_sv_1: %d\n", deviceParam.unit_int_sv_1);
        Serial.printf("unit_int_sv_2: %d\n", deviceParam.unit_int_sv_2);
        Serial.printf("unit_int_sv_3: %d\n", deviceParam.unit_int_sv_3);
        Serial.printf("unit_int_sv_4: %d\n", deviceParam.unit_int_sv_4);
        Serial.printf("unit_int_sv_5: %d\n", deviceParam.unit_int_sv_5);

        // unit pv
        Serial.printf("unit_pv_1: %d\n", deviceParam.unit_pv_1);
        Serial.printf("unit_pv_2: %d\n", deviceParam.unit_pv_2);
        Serial.printf("unit_pv_3: %d\n", deviceParam.unit_pv_3);
        Serial.printf("unit_pv_4: %d\n", deviceParam.unit_pv_4);
        Serial.printf("unit_pv_5: %d\n", deviceParam.unit_pv_5);

        // chart max
        Serial.printf("chart_max_1: %d\n", deviceParam.chart_max_1);
        Serial.printf("chart_max_2: %d\n", deviceParam.chart_max_2);
        Serial.printf("chart_max_3: %d\n", deviceParam.chart_max_3);
        Serial.printf("chart_max_4: %d\n", deviceParam.chart_max_4);
        Serial.printf("chart_max_5: %d\n", deviceParam.chart_max_5);

        // chart min
        Serial.printf("chart_min_1: %d\n", deviceParam.chart_min_1);
        Serial.printf("chart_min_2: %d\n", deviceParam.chart_min_2);
        Serial.printf("chart_min_3: %d\n", deviceParam.chart_min_3);
        Serial.printf("chart_min_4: %d\n", deviceParam.chart_min_4);
        Serial.printf("chart_min_5: %d\n", deviceParam.chart_min_5);
    }
    else
    {
        Serial.println("EEPROM data invalid or version mismatch.");
    }

    EEPROM.end();
}
void loadEEPROM()
{
    loadEEPROM(ResBuff);
}



void update_registry_from_struct(ModbusRegisterValues newvalue)
{
    // flag
    mb.Hreg(lock_flag, newvalue.lock_flag ? 1 : 0);
    mb.Hreg(run_flag,  newvalue.run_flag  ? 1 : 0);

    // display
    mb.Hreg(display_pv_1, (uint16_t)newvalue.display_pv_1);
    mb.Hreg(display_pv_2, (uint16_t)newvalue.display_pv_2);
    mb.Hreg(display_pv_3, (uint16_t)newvalue.display_pv_3);
    mb.Hreg(display_pv_4, (uint16_t)newvalue.display_pv_4);
    mb.Hreg(display_pv_5, (uint16_t)newvalue.display_pv_5);

    // progress
    mb.Hreg(run_progress_max, (uint16_t)newvalue.run_progress_max);
    mb.Hreg(run_progress,     (uint16_t)newvalue.run_progress);

    // run sv
    mb.Hreg(run_sv_1,      (uint16_t)newvalue.run_sv_1);
    mb.Hreg(run_sv_2,      (uint16_t)newvalue.run_sv_2);
    mb.Hreg(run_sv_3,      (uint16_t)newvalue.run_sv_3);
    mb.Hreg(run_sv_4,      (uint16_t)newvalue.run_sv_4);
    mb.Hreg(run_sv_5,      (uint16_t)newvalue.run_sv_5);
    mb.Hreg(run_sv_select, (uint16_t)newvalue.run_sv_select);
    mb.Hreg(run_sv_status, (uint16_t)newvalue.run_sv_status);

    // unit read interval (SV)
    mb.Hreg(unit_int_sv_1, (uint16_t)newvalue.unit_int_sv_1);
    mb.Hreg(unit_int_sv_2, (uint16_t)newvalue.unit_int_sv_2);
    mb.Hreg(unit_int_sv_3, (uint16_t)newvalue.unit_int_sv_3);
    mb.Hreg(unit_int_sv_4, (uint16_t)newvalue.unit_int_sv_4);
    mb.Hreg(unit_int_sv_5, (uint16_t)newvalue.unit_int_sv_5);

    // unit read pv
    mb.Hreg(unit_pv_1, (uint16_t)newvalue.unit_pv_1);
    mb.Hreg(unit_pv_2, (uint16_t)newvalue.unit_pv_2);
    mb.Hreg(unit_pv_3, (uint16_t)newvalue.unit_pv_3);
    mb.Hreg(unit_pv_4, (uint16_t)newvalue.unit_pv_4);
    mb.Hreg(unit_pv_5, (uint16_t)newvalue.unit_pv_5);

    // chart max
    mb.Hreg(chart_max_1, (uint16_t)newvalue.chart_max_1);
    mb.Hreg(chart_max_2, (uint16_t)newvalue.chart_max_2);
    mb.Hreg(chart_max_3, (uint16_t)newvalue.chart_max_3);
    mb.Hreg(chart_max_4, (uint16_t)newvalue.chart_max_4);
    mb.Hreg(chart_max_5, (uint16_t)newvalue.chart_max_5);

    // chart min
    mb.Hreg(chart_min_1, (uint16_t)newvalue.chart_min_1);
    mb.Hreg(chart_min_2, (uint16_t)newvalue.chart_min_2);
    mb.Hreg(chart_min_3, (uint16_t)newvalue.chart_min_3);
    mb.Hreg(chart_min_4, (uint16_t)newvalue.chart_min_4);
    mb.Hreg(chart_min_5, (uint16_t)newvalue.chart_min_5);
}
void update_registry_from_struct()
{
    update_registry_from_struct(ResBuff);
}



void update_struct_from_registry(ModbusRegisterValues &newvalue)
{
    // flag
    newvalue.lock_flag = (mb.Hreg(lock_flag) > 0);
    newvalue.run_flag  = (mb.Hreg(run_flag) > 0);

    // display
    newvalue.display_pv_1 = (int32_t)mb.Hreg(display_pv_1);
    newvalue.display_pv_2 = (int32_t)mb.Hreg(display_pv_2);
    newvalue.display_pv_3 = (int32_t)mb.Hreg(display_pv_3);
    newvalue.display_pv_4 = (int32_t)mb.Hreg(display_pv_4);
    newvalue.display_pv_5 = (int32_t)mb.Hreg(display_pv_5);

    // progress
    newvalue.run_progress_max = (int32_t)mb.Hreg(run_progress_max);
    newvalue.run_progress     = (int32_t)mb.Hreg(run_progress);

    // run sv
    newvalue.run_sv_1      = (int32_t)mb.Hreg(run_sv_1);
    newvalue.run_sv_2      = (int32_t)mb.Hreg(run_sv_2);
    newvalue.run_sv_3      = (int32_t)mb.Hreg(run_sv_3);
    newvalue.run_sv_4      = (int32_t)mb.Hreg(run_sv_4);
    newvalue.run_sv_5      = (int32_t)mb.Hreg(run_sv_5);
    newvalue.run_sv_select = (int32_t)mb.Hreg(run_sv_select);
    newvalue.run_sv_status = (int32_t)mb.Hreg(run_sv_status);

    // unit read interval (SV)
    newvalue.unit_int_sv_1 = (int32_t)mb.Hreg(unit_int_sv_1);
    newvalue.unit_int_sv_2 = (int32_t)mb.Hreg(unit_int_sv_2);
    newvalue.unit_int_sv_3 = (int32_t)mb.Hreg(unit_int_sv_3);
    newvalue.unit_int_sv_4 = (int32_t)mb.Hreg(unit_int_sv_4);
    newvalue.unit_int_sv_5 = (int32_t)mb.Hreg(unit_int_sv_5);

    // unit read pv
    newvalue.unit_pv_1 = (int32_t)mb.Hreg(unit_pv_1);
    newvalue.unit_pv_2 = (int32_t)mb.Hreg(unit_pv_2);
    newvalue.unit_pv_3 = (int32_t)mb.Hreg(unit_pv_3);
    newvalue.unit_pv_4 = (int32_t)mb.Hreg(unit_pv_4);
    newvalue.unit_pv_5 = (int32_t)mb.Hreg(unit_pv_5);

    // chart max
    newvalue.chart_max_1 = (int32_t)mb.Hreg(chart_max_1);
    newvalue.chart_max_2 = (int32_t)mb.Hreg(chart_max_2);
    newvalue.chart_max_3 = (int32_t)mb.Hreg(chart_max_3);
    newvalue.chart_max_4 = (int32_t)mb.Hreg(chart_max_4);
    newvalue.chart_max_5 = (int32_t)mb.Hreg(chart_max_5);

    // chart min
    newvalue.chart_min_1 = (int32_t)mb.Hreg(chart_min_1);
    newvalue.chart_min_2 = (int32_t)mb.Hreg(chart_min_2);
    newvalue.chart_min_3 = (int32_t)mb.Hreg(chart_min_3);
    newvalue.chart_min_4 = (int32_t)mb.Hreg(chart_min_4);
    newvalue.chart_min_5 = (int32_t)mb.Hreg(chart_min_5);
}
void update_struct_from_registry()
{
    update_struct_from_registry(ResBuff);
}

void update_struct_from_device(ModbusRegisterValues &newvalue)
{
    // flag
    newvalue.lock_flag = get_var_lock_flag();
    newvalue.run_flag  = get_var_run_flag();

    // display
    newvalue.display_pv_1 = get_var_display_pv_1();
    newvalue.display_pv_2 = get_var_display_pv_2();
    newvalue.display_pv_3 = get_var_display_pv_3();
    newvalue.display_pv_4 = get_var_display_pv_4();
    newvalue.display_pv_5 = get_var_display_pv_5();

    // progress
    newvalue.run_progress_max = get_var_run_progress_max();
    newvalue.run_progress     = get_var_run_progress();

    // run sv
    newvalue.run_sv_1      = get_var_run_sv_1();
    newvalue.run_sv_2      = get_var_run_sv_2();
    newvalue.run_sv_3      = get_var_run_sv_3();
    newvalue.run_sv_4      = get_var_run_sv_4();
    newvalue.run_sv_5      = get_var_run_sv_5();
    newvalue.run_sv_select = get_var_run_sv_select();
    newvalue.run_sv_status = get_var_run_sv_status();

    // unit interval
    newvalue.unit_int_sv_1 = get_var_unit_int_sv_1();
    newvalue.unit_int_sv_2 = get_var_unit_int_sv_2();
    newvalue.unit_int_sv_3 = get_var_unit_int_sv_3();
    newvalue.unit_int_sv_4 = get_var_unit_int_sv_4();
    newvalue.unit_int_sv_5 = get_var_unit_int_sv_5();

    // unit pv
    newvalue.unit_pv_1 = get_var_unit_pv_1();
    newvalue.unit_pv_2 = get_var_unit_pv_2();
    newvalue.unit_pv_3 = get_var_unit_pv_3();
    newvalue.unit_pv_4 = get_var_unit_pv_4();
    newvalue.unit_pv_5 = get_var_unit_pv_5();

    // chart max
    newvalue.chart_max_1 = get_var_chart_max_1();
    newvalue.chart_max_2 = get_var_chart_max_2();
    newvalue.chart_max_3 = get_var_chart_max_3();
    newvalue.chart_max_4 = get_var_chart_max_4();
    newvalue.chart_max_5 = get_var_chart_max_5();

    // chart min
    newvalue.chart_min_1 = get_var_chart_min_1();
    newvalue.chart_min_2 = get_var_chart_min_2();
    newvalue.chart_min_3 = get_var_chart_min_3();
    newvalue.chart_min_4 = get_var_chart_min_4();
    newvalue.chart_min_5 = get_var_chart_min_5();
}

void update_struct_from_device()
{
    update_struct_from_device(ResBuff);
    ResPrev = ResBuff;
}

template <typename T>
void update_device_call(T newValue, T &previous, void (*callback)(T))
{
    if (newValue != previous)
    {
        callback(newValue);
        previous = newValue;
    }
}

void update_device_from_struct(ModbusRegisterValues newvalue, ModbusRegisterValues previous)
{
    // flag
    update_device_call(newvalue.lock_flag, previous.lock_flag, set_var_lock_flag);
    update_device_call(newvalue.run_flag,  previous.run_flag,  set_var_run_flag);

    // display
    update_device_call(newvalue.display_pv_1, previous.display_pv_1, set_var_display_pv_1);
    update_device_call(newvalue.display_pv_2, previous.display_pv_2, set_var_display_pv_2);
    update_device_call(newvalue.display_pv_3, previous.display_pv_3, set_var_display_pv_3);
    update_device_call(newvalue.display_pv_4, previous.display_pv_4, set_var_display_pv_4);
    update_device_call(newvalue.display_pv_5, previous.display_pv_5, set_var_display_pv_5);

    // progress
    update_device_call(newvalue.run_progress_max, previous.run_progress_max, set_var_run_progress_max);
    update_device_call(newvalue.run_progress,     previous.run_progress,     set_var_run_progress);

    // run sv
    update_device_call(newvalue.run_sv_1,      previous.run_sv_1,      set_var_run_sv_1);
    update_device_call(newvalue.run_sv_2,      previous.run_sv_2,      set_var_run_sv_2);
    update_device_call(newvalue.run_sv_3,      previous.run_sv_3,      set_var_run_sv_3);
    update_device_call(newvalue.run_sv_4,      previous.run_sv_4,      set_var_run_sv_4);
    update_device_call(newvalue.run_sv_5,      previous.run_sv_5,      set_var_run_sv_5);
    update_device_call(newvalue.run_sv_select, previous.run_sv_select, set_var_run_sv_select);
    update_device_call(newvalue.run_sv_status, previous.run_sv_status, set_var_run_sv_status);

    // unit interval
    update_device_call(newvalue.unit_int_sv_1, previous.unit_int_sv_1, set_var_unit_int_sv_1);
    update_device_call(newvalue.unit_int_sv_2, previous.unit_int_sv_2, set_var_unit_int_sv_2);
    update_device_call(newvalue.unit_int_sv_3, previous.unit_int_sv_3, set_var_unit_int_sv_3);
    update_device_call(newvalue.unit_int_sv_4, previous.unit_int_sv_4, set_var_unit_int_sv_4);
    update_device_call(newvalue.unit_int_sv_5, previous.unit_int_sv_5, set_var_unit_int_sv_5);

    // unit pv
    update_device_call(newvalue.unit_pv_1, previous.unit_pv_1, set_var_unit_pv_1);
    update_device_call(newvalue.unit_pv_2, previous.unit_pv_2, set_var_unit_pv_2);
    update_device_call(newvalue.unit_pv_3, previous.unit_pv_3, set_var_unit_pv_3);
    update_device_call(newvalue.unit_pv_4, previous.unit_pv_4, set_var_unit_pv_4);
    update_device_call(newvalue.unit_pv_5, previous.unit_pv_5, set_var_unit_pv_5);

    // chart max
    update_device_call(newvalue.chart_max_1, previous.chart_max_1, set_var_chart_max_1);
    update_device_call(newvalue.chart_max_2, previous.chart_max_2, set_var_chart_max_2);
    update_device_call(newvalue.chart_max_3, previous.chart_max_3, set_var_chart_max_3);
    update_device_call(newvalue.chart_max_4, previous.chart_max_4, set_var_chart_max_4);
    update_device_call(newvalue.chart_max_5, previous.chart_max_5, set_var_chart_max_5);

    // chart min
    update_device_call(newvalue.chart_min_1, previous.chart_min_1, set_var_chart_min_1);
    update_device_call(newvalue.chart_min_2, previous.chart_min_2, set_var_chart_min_2);
    update_device_call(newvalue.chart_min_3, previous.chart_min_3, set_var_chart_min_3);
    update_device_call(newvalue.chart_min_4, previous.chart_min_4, set_var_chart_min_4);
    update_device_call(newvalue.chart_min_5, previous.chart_min_5, set_var_chart_min_5);
}
void update_device_from_struct()
{
    update_device_from_struct(ResBuff, ResPrev);
}
