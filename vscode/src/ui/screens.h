#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *unit_config;
    lv_obj_t *key_board;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *label_unit_pv_6;
    lv_obj_t *label_unit_pv_7;
    lv_obj_t *label_unit_pv_8;
    lv_obj_t *label_unit_pv_9;
    lv_obj_t *label_unit_pv_10;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *roller_sv_select;
    lv_obj_t *label_display_pv_1_main;
    lv_obj_t *line_1;
    lv_obj_t *line_2;
    lv_obj_t *label_display_pv_1;
    lv_obj_t *label_display_pv_2;
    lv_obj_t *label_display_pv_3;
    lv_obj_t *label_display_pv_4;
    lv_obj_t *label_display_pv_5;
    lv_obj_t *label_unit_pv_1;
    lv_obj_t *label_unit_pv_2;
    lv_obj_t *label_unit_pv_3;
    lv_obj_t *label_unit_pv_4;
    lv_obj_t *label_unit_pv_5;
    lv_obj_t *label_unit_pv_title_1;
    lv_obj_t *label_unit_pv_title_2;
    lv_obj_t *label_unit_pv_title_3;
    lv_obj_t *label_unit_pv_title_4;
    lv_obj_t *label_unit_pv_title_5;
    lv_obj_t *label_display_pv_title_1;
    lv_obj_t *label_display_pv_title_2;
    lv_obj_t *label_display_pv_title_3;
    lv_obj_t *label_display_pv_title_4;
    lv_obj_t *label_display_pv_title_5;
    lv_obj_t *line_3;
    lv_obj_t *line_4;
    lv_obj_t *slider_progress;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *label_unit_pv_title_6;
    lv_obj_t *label_unit_pv_title_7;
    lv_obj_t *label_unit_pv_title_8;
    lv_obj_t *label_unit_pv_title_9;
    lv_obj_t *label_unit_pv_title_10;
    lv_obj_t *label_unit_pv_11;
    lv_obj_t *label_unit_pv_12;
    lv_obj_t *label_unit_pv_13;
    lv_obj_t *label_unit_pv_14;
    lv_obj_t *label_unit_pv_15;
    lv_obj_t *chart_1;
    lv_obj_t *chart_2;
    lv_obj_t *chart_3;
    lv_obj_t *chart_4;
    lv_obj_t *chart_5;
    lv_obj_t *obj16;
    lv_obj_t *textarea_keyboard_input;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_UNIT_CONFIG = 2,
    SCREEN_ID_KEY_BOARD = 3,
};

void create_screen_main();
void tick_screen_main();

void create_screen_unit_config();
void tick_screen_unit_config();

void create_screen_key_board();
void tick_screen_key_board();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/