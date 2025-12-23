#ifndef MY_MAIN_H
#define MY_MAIN_H

#include <ModbusRTU.h>
#include "my_unit_control.h"

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
void setup_LVGL_chart_range();

#endif