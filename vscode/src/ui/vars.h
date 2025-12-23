#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

typedef enum {
    keyID_unit_int_sv_1 = 1,
    keyID_unit_int_sv_2 = 2,
    keyID_unit_int_sv_3 = 3,
    keyID_unit_int_sv_4 = 4,
    keyID_unit_int_sv_5 = 5,
    keyID_run_progress_max = 6,
    keyID_chart_max_1 = 7,
    keyID_chart_max_2 = 8,
    keyID_chart_max_3 = 9,
    keyID_chart_max_4 = 10,
    keyID_chart_max_5 = 11,
    keyID_chart_min_1 = 12,
    keyID_chart_min_2 = 13,
    keyID_chart_min_3 = 14,
    keyID_chart_min_4 = 15,
    keyID_chart_min_5 = 16
} keyID;

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_RUN_SV_LIST = 0,
    FLOW_GLOBAL_VARIABLE_CONFIG_TARGET_ITEM_INDEX = 1,
    FLOW_GLOBAL_VARIABLE_UNITCONFIG_APPLY = 2
};

// Native global variables

extern int32_t get_var_run_sv_status();
extern void set_var_run_sv_status(int32_t value);
extern int32_t get_var_run_sv_select();
extern void set_var_run_sv_select(int32_t value);
extern int32_t get_var_run_progress();
extern void set_var_run_progress(int32_t value);
extern int32_t get_var_run_progress_max();
extern void set_var_run_progress_max(int32_t value);
extern int32_t get_var_run_sv_1();
extern void set_var_run_sv_1(int32_t value);
extern int32_t get_var_run_sv_2();
extern void set_var_run_sv_2(int32_t value);
extern int32_t get_var_run_sv_3();
extern void set_var_run_sv_3(int32_t value);
extern int32_t get_var_run_sv_4();
extern void set_var_run_sv_4(int32_t value);
extern int32_t get_var_run_sv_5();
extern void set_var_run_sv_5(int32_t value);
extern int32_t get_var_unit_int_sv_1();
extern void set_var_unit_int_sv_1(int32_t value);
extern int32_t get_var_unit_int_sv_2();
extern void set_var_unit_int_sv_2(int32_t value);
extern int32_t get_var_unit_int_sv_3();
extern void set_var_unit_int_sv_3(int32_t value);
extern int32_t get_var_unit_int_sv_4();
extern void set_var_unit_int_sv_4(int32_t value);
extern int32_t get_var_unit_int_sv_5();
extern void set_var_unit_int_sv_5(int32_t value);
extern int32_t get_var_unit_pv_1();
extern void set_var_unit_pv_1(int32_t value);
extern int32_t get_var_unit_pv_2();
extern void set_var_unit_pv_2(int32_t value);
extern int32_t get_var_unit_pv_3();
extern void set_var_unit_pv_3(int32_t value);
extern int32_t get_var_unit_pv_4();
extern void set_var_unit_pv_4(int32_t value);
extern int32_t get_var_unit_pv_5();
extern void set_var_unit_pv_5(int32_t value);
extern int32_t get_var_display_pv_1();
extern void set_var_display_pv_1(int32_t value);
extern int32_t get_var_display_pv_2();
extern void set_var_display_pv_2(int32_t value);
extern int32_t get_var_display_pv_3();
extern void set_var_display_pv_3(int32_t value);
extern int32_t get_var_display_pv_4();
extern void set_var_display_pv_4(int32_t value);
extern int32_t get_var_display_pv_5();
extern void set_var_display_pv_5(int32_t value);
extern bool get_var_run_flag();
extern void set_var_run_flag(bool value);
extern bool get_var_lock_flag();
extern void set_var_lock_flag(bool value);
extern int32_t get_var_chart_max_1();
extern void set_var_chart_max_1(int32_t value);
extern int32_t get_var_chart_max_2();
extern void set_var_chart_max_2(int32_t value);
extern int32_t get_var_chart_max_3();
extern void set_var_chart_max_3(int32_t value);
extern int32_t get_var_chart_max_4();
extern void set_var_chart_max_4(int32_t value);
extern int32_t get_var_chart_max_5();
extern void set_var_chart_max_5(int32_t value);
extern int32_t get_var_chart_min_1();
extern void set_var_chart_min_1(int32_t value);
extern int32_t get_var_chart_min_2();
extern void set_var_chart_min_2(int32_t value);
extern int32_t get_var_chart_min_3();
extern void set_var_chart_min_3(int32_t value);
extern int32_t get_var_chart_min_4();
extern void set_var_chart_min_4(int32_t value);
extern int32_t get_var_chart_min_5();
extern void set_var_chart_min_5(int32_t value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/