#include <Arduino.h>
#include <M5Unified.h>

#include "my_unit_control.h"
#include "main.h"

extern "C" void action_save_device_parameter(lv_event_t *e)
{
    update_MODBUS_Registry_from_device();
    update_struct_from_MODBUS_Registry(ResBuff);
    saveEEPROM(ResBuff);
}
