#include <Arduino.h>
#include <M5Unified.h>
#include <Wire.h>
#include <Unit_Sonic.h>
#include <VL53L0X.h>
#include <VL53L1X.h>
#include <EEPROM.h>

#include "my_unit_control.h"
#include "main.h"

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

    Serial.printf("lock_flag: %d\n", deviceParam.lock_flag);
    Serial.printf("run_flag: %d\n", deviceParam.run_flag);
    Serial.printf("display_pv_1: %d\n", deviceParam.display_pv_1);
    Serial.printf("display_pv_2: %d\n", deviceParam.display_pv_2);
    Serial.printf("display_pv_3: %d\n", deviceParam.display_pv_3);
    Serial.printf("display_pv_4: %d\n", deviceParam.display_pv_4);
    Serial.printf("display_pv_5: %d\n", deviceParam.display_pv_5);
    Serial.printf("run_progress_max: %d\n", deviceParam.run_progress_max);
    Serial.printf("run_progress: %d\n", deviceParam.run_progress);
    Serial.printf("run_sv_1: %d\n", deviceParam.run_sv_1);
    Serial.printf("run_sv_2: %d\n", deviceParam.run_sv_2);
    Serial.printf("run_sv_3: %d\n", deviceParam.run_sv_3);
    Serial.printf("run_sv_4: %d\n", deviceParam.run_sv_4);
    Serial.printf("run_sv_5: %d\n", deviceParam.run_sv_5);
    Serial.printf("run_sv_select: %d\n", deviceParam.run_sv_select);
    Serial.printf("run_sv_status: %d\n", deviceParam.run_sv_status);
    Serial.printf("unit_int_sv_1: %d\n", deviceParam.unit_int_sv_1);
    Serial.printf("unit_int_sv_2: %d\n", deviceParam.unit_int_sv_2);
    Serial.printf("unit_int_sv_3: %d\n", deviceParam.unit_int_sv_3);
    Serial.printf("unit_int_sv_4: %d\n", deviceParam.unit_int_sv_4);
    Serial.printf("unit_int_sv_5: %d\n", deviceParam.unit_int_sv_5);
    Serial.printf("unit_pv_1: %d\n", deviceParam.unit_pv_1);
    Serial.printf("unit_pv_2: %d\n", deviceParam.unit_pv_2);
    Serial.printf("unit_pv_3: %d\n", deviceParam.unit_pv_3);
    Serial.printf("unit_pv_4: %d\n", deviceParam.unit_pv_4);
    Serial.printf("unit_pv_5: %d\n", deviceParam.unit_pv_5);
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

        Serial.printf("lock_flag: %d\n", deviceParam.lock_flag);
        Serial.printf("run_flag: %d\n", deviceParam.run_flag);
        Serial.printf("display_pv_1: %d\n", deviceParam.display_pv_1);
        Serial.printf("display_pv_2: %d\n", deviceParam.display_pv_2);
        Serial.printf("display_pv_3: %d\n", deviceParam.display_pv_3);
        Serial.printf("display_pv_4: %d\n", deviceParam.display_pv_4);
        Serial.printf("display_pv_5: %d\n", deviceParam.display_pv_5);
        Serial.printf("run_progress_max: %d\n", deviceParam.run_progress_max);
        Serial.printf("run_progress: %d\n", deviceParam.run_progress);
        Serial.printf("run_sv_1: %d\n", deviceParam.run_sv_1);
        Serial.printf("run_sv_2: %d\n", deviceParam.run_sv_2);
        Serial.printf("run_sv_3: %d\n", deviceParam.run_sv_3);
        Serial.printf("run_sv_4: %d\n", deviceParam.run_sv_4);
        Serial.printf("run_sv_5: %d\n", deviceParam.run_sv_5);
        Serial.printf("run_sv_select: %d\n", deviceParam.run_sv_select);
        Serial.printf("run_sv_status: %d\n", deviceParam.run_sv_status);
        Serial.printf("unit_int_sv_1: %d\n", deviceParam.unit_int_sv_1);
        Serial.printf("unit_int_sv_2: %d\n", deviceParam.unit_int_sv_2);
        Serial.printf("unit_int_sv_3: %d\n", deviceParam.unit_int_sv_3);
        Serial.printf("unit_int_sv_4: %d\n", deviceParam.unit_int_sv_4);
        Serial.printf("unit_int_sv_5: %d\n", deviceParam.unit_int_sv_5);
        Serial.printf("unit_pv_1: %d\n", deviceParam.unit_pv_1);
        Serial.printf("unit_pv_2: %d\n", deviceParam.unit_pv_2);
        Serial.printf("unit_pv_3: %d\n", deviceParam.unit_pv_3);
        Serial.printf("unit_pv_4: %d\n", deviceParam.unit_pv_4);
        Serial.printf("unit_pv_5: %d\n", deviceParam.unit_pv_5);
    }
    else
    {
        Serial.println("EEPROM data invalid or version mismatch.");
    }

    EEPROM.end();
}
