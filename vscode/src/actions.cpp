#include <Arduino.h>
#include <M5Unified.h>

#include "my_unit_control.h"
#include "main.h"

extern "C" void action_save_device_parameter(lv_event_t *e)
{
    update_struct_from_device();
    setup_LVGL_chart_range();
    saveEEPROM();
}
