#include <Arduino.h>
#include <M5Unified.h>
#include <Unit_Sonic.h>
#include <VL53L1X.h>
#include "ui/vars.h"
#include "ui/screens.h"

#include "main.h"

#ifndef MY_UNIT_CONTROL_H
#define MY_UNIT_CONTROL_H


#define EEPROM_SIZE 512   // 必要に応じてサイズ調整
#define EEPROM_ADDR 0     // 先頭から保存

// 識別子とバージョン
const uint32_t EEPROM_ID_DPRM = 0x4450524D; // 'DPRM'
const uint8_t EEPROM_VERSION_DPRM = 1;



// ===== Modbus config =====
#define SLAVE_ID 2

// Register adress offset enum
enum HoldingRegister
{
    lock_flag = 0,
    run_flag,
    display_pv_1,
    display_pv_2,
    display_pv_3,
    display_pv_4,
    display_pv_5,
    run_progress_max,
    run_progress,
    run_sv_1,
    run_sv_2,
    run_sv_3,
    run_sv_4,
    run_sv_5,
    run_sv_select,
    run_sv_status,
    unit_int_sv_1,
    unit_int_sv_2,
    unit_int_sv_3,
    unit_int_sv_4,
    unit_int_sv_5,
    unit_pv_1,
    unit_pv_2,
    unit_pv_3,
    unit_pv_4,
    unit_pv_5,
    chart_max_1,
    chart_max_2,
    chart_max_3,
    chart_max_4,
    chart_max_5,
    chart_min_1,
    chart_min_2,
    chart_min_3,
    chart_min_4,
    chart_min_5,
    REG_COUNT
};

struct ModbusRegisterValues
{
    bool lock_flag;
    bool run_flag;
    int32_t display_pv_1;
    int32_t display_pv_2;
    int32_t display_pv_3;
    int32_t display_pv_4;
    int32_t display_pv_5;
    int32_t run_progress_max;
    int32_t run_progress;
    int32_t run_sv_1;
    int32_t run_sv_2;
    int32_t run_sv_3;
    int32_t run_sv_4;
    int32_t run_sv_5;
    int32_t run_sv_select;
    int32_t run_sv_status;
    int32_t unit_int_sv_1;
    int32_t unit_int_sv_2;
    int32_t unit_int_sv_3;
    int32_t unit_int_sv_4;
    int32_t unit_int_sv_5;
    int32_t unit_pv_1;
    int32_t unit_pv_2;
    int32_t unit_pv_3;
    int32_t unit_pv_4;
    int32_t unit_pv_5;
    int32_t chart_max_1;
    int32_t chart_max_2;
    int32_t chart_max_3;
    int32_t chart_max_4;
    int32_t chart_max_5;
    int32_t chart_min_1;
    int32_t chart_min_2;
    int32_t chart_min_3;
    int32_t chart_min_4;
    int32_t chart_min_5;
};

// Modbus object
extern ModbusRTU mb;
extern ModbusRegisterValues ResBuff;

void loadEEPROM();
void saveEEPROM();

void update_registry_from_struct();
void update_struct_from_registry();
void update_device_from_struct();
void update_struct_from_device();

#endif