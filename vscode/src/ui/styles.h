#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: Label_H_1
lv_style_t *get_style_label_h_1_MAIN_DEFAULT();
void add_style_label_h_1(lv_obj_t *obj);
void remove_style_label_h_1(lv_obj_t *obj);

// Style: Label_H_2
lv_style_t *get_style_label_h_2_MAIN_DEFAULT();
void add_style_label_h_2(lv_obj_t *obj);
void remove_style_label_h_2(lv_obj_t *obj);

// Style: Label_H_3
lv_style_t *get_style_label_h_3_MAIN_DEFAULT();
void add_style_label_h_3(lv_obj_t *obj);
void remove_style_label_h_3(lv_obj_t *obj);

// Style: Label_Default
lv_style_t *get_style_label_default_MAIN_DEFAULT();
void add_style_label_default(lv_obj_t *obj);
void remove_style_label_default(lv_obj_t *obj);

// Style: Button_Apply
lv_style_t *get_style_button_apply_MAIN_DEFAULT();
void add_style_button_apply(lv_obj_t *obj);
void remove_style_button_apply(lv_obj_t *obj);

// Style: Button_Default
lv_style_t *get_style_button_default_MAIN_DEFAULT();
lv_style_t *get_style_button_default_MAIN_DISABLED();
void add_style_button_default(lv_obj_t *obj);
void remove_style_button_default(lv_obj_t *obj);

// Style: Roller_Default
lv_style_t *get_style_roller_default_MAIN_DEFAULT();
lv_style_t *get_style_roller_default_SELECTED_DEFAULT();
void add_style_roller_default(lv_obj_t *obj);
void remove_style_roller_default(lv_obj_t *obj);

// Style: Label_Normal_Right
lv_style_t *get_style_label_normal_right_MAIN_DEFAULT();
void add_style_label_normal_right(lv_obj_t *obj);
void remove_style_label_normal_right(lv_obj_t *obj);

// Style: Tabview_Default
lv_style_t *get_style_tabview_default_MAIN_DEFAULT();
void add_style_tabview_default(lv_obj_t *obj);
void remove_style_tabview_default(lv_obj_t *obj);

// Style: Tab_Default
lv_style_t *get_style_tab_default_MAIN_DEFAULT();
void add_style_tab_default(lv_obj_t *obj);
void remove_style_tab_default(lv_obj_t *obj);

// Style: Textarea_Default
lv_style_t *get_style_textarea_default_MAIN_DEFAULT();
void add_style_textarea_default(lv_obj_t *obj);
void remove_style_textarea_default(lv_obj_t *obj);

// Style: Keyboard_Default
lv_style_t *get_style_keyboard_default_MAIN_DEFAULT();
void add_style_keyboard_default(lv_obj_t *obj);
void remove_style_keyboard_default(lv_obj_t *obj);

// Style: Chart_Default
void add_style_chart_default(lv_obj_t *obj);
void remove_style_chart_default(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/