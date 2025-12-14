#ifndef MY_MAIN_H
#define MY_MAIN_H

#include <ModbusRTU.h>

// Tab5 RS485
#define MODBUS_TX_PIN 20 // RS485
#define MODBUS_RX_PIN 21 // RS485
#define MODBUS_DE_PIN 34 // RS485

// Core2 Port.C
// #define MODBUS_TX_PIN 14 //(HY2.0-4P/Yellow)Connect RS485 module Rx
// #define MODBUS_RX_PIN 13 //(HY2.0-4P/White)Connect RS485 module Tx
// #define MODBUS_DE_PIN 20 // Dammy PIN attach Interrupt RS485 loop back clear code (M5Core2 N.C.)

// CoreS3 series Port.C
// #define MODBUS_TX_PIN 17 //(HY2.0-4P/Yellow)Connect RS485 module Rx
// #define MODBUS_RX_PIN 18 //(HY2.0-4P/White)Connect RS485 module Tx

#define PortA_SDA 53 // M5Tab5 PortA(SDA)
#define PortA_SCL 54 // M5Tab5 PortA(SCL)

// #define MODBUS_BAUD 115200
#define MODBUS_BAUD 9600

extern bool inUpdateCall;

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
    REG_COUNT
};

struct ModbusRegisterValues
{
    bool run;
    bool freeSwitch;
    int32_t mv;
    int32_t sv;
    int32_t rem;
    int32_t remRate;
    float info_1;
    float info_2;
    float info_3;
};

// Modbus object
extern ModbusRTU mb;

#endif