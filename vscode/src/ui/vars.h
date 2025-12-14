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
    keyID_run_progress_max = 6
} keyID;

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_RUN_SV_LIST = 0,
    FLOW_GLOBAL_VARIABLE_CONFIG_TARGET_ITEM_INDEX = 1
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


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/