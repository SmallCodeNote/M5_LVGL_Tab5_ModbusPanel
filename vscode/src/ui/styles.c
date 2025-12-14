#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: Label_H_1
//

void init_style_label_h_1_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_noto_sans_mono_180);
};

lv_style_t *get_style_label_h_1_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_h_1_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_h_1(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_h_1_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_h_1(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_h_1_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Label_H_2
//

void init_style_label_h_2_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_noto_sans_mono_120);
};

lv_style_t *get_style_label_h_2_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_h_2_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_h_2(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_h_2_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_h_2(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_h_2_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Label_H_3
//

void init_style_label_h_3_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_noto_sans_mono_080);
};

lv_style_t *get_style_label_h_3_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_h_3_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_h_3(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_h_3_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_h_3(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_h_3_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Label_Default
//

void init_style_label_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_48);
};

lv_style_t *get_style_label_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_default_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Button_Apply
//

void init_style_button_apply_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_48);
    lv_style_set_bg_color(style, lv_color_hex(0xff8a8a8a));
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_button_apply_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_apply_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_button_apply(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_apply_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_button_apply(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_apply_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Button_Default
//

void init_style_button_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_48);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_button_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_default_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_button_default_MAIN_DISABLED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff8a8a8a));
};

lv_style_t *get_style_button_default_MAIN_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_default_MAIN_DISABLED(style);
    }
    return style;
};

void add_style_button_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_button_default_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

void remove_style_button_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_button_default_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

//
// Style: Roller_Default
//

void init_style_roller_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_48);
    lv_style_set_border_color(style, lv_color_hex(0xffe2ecfd));
    lv_style_set_border_width(style, 5);
    lv_style_set_shadow_color(style, lv_color_hex(0xff3299fe));
    lv_style_set_shadow_opa(style, 128);
    lv_style_set_shadow_width(style, 6);
    lv_style_set_shadow_spread(style, 6);
};

lv_style_t *get_style_roller_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_roller_default_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_roller_default_SELECTED_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_noto_sans_mono_080);
};

lv_style_t *get_style_roller_default_SELECTED_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_roller_default_SELECTED_DEFAULT(style);
    }
    return style;
};

void add_style_roller_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_roller_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_roller_default_SELECTED_DEFAULT(), LV_PART_SELECTED | LV_STATE_DEFAULT);
};

void remove_style_roller_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_roller_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_roller_default_SELECTED_DEFAULT(), LV_PART_SELECTED | LV_STATE_DEFAULT);
};

//
// Style: Label_Normal_Right
//

void init_style_label_normal_right_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_48);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_RIGHT);
};

lv_style_t *get_style_label_normal_right_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_normal_right_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_normal_right(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_normal_right_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_normal_right(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_normal_right_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Tabview_Default
//

void init_style_tabview_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_48);
};

lv_style_t *get_style_tabview_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tabview_default_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tabview_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tabview_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tabview_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tabview_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Tab_Default
//

void init_style_tab_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_48);
};

lv_style_t *get_style_tab_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tab_default_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tab_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tab_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tab_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tab_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Textarea_Default
//

void init_style_textarea_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_align(style, LV_TEXT_ALIGN_RIGHT);
};

lv_style_t *get_style_textarea_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_textarea_default_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_textarea_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_textarea_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_textarea_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_textarea_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Keyboard_Default
//

void init_style_keyboard_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_48);
};

lv_style_t *get_style_keyboard_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_keyboard_default_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_keyboard_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_keyboard_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_keyboard_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_keyboard_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Chart_Default
//

void add_style_chart_default(lv_obj_t *obj) {
    (void)obj;
};

void remove_style_chart_default(lv_obj_t *obj) {
    (void)obj;
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_label_h_1,
        add_style_label_h_2,
        add_style_label_h_3,
        add_style_label_default,
        add_style_button_apply,
        add_style_button_default,
        add_style_roller_default,
        add_style_label_normal_right,
        add_style_tabview_default,
        add_style_tab_default,
        add_style_textarea_default,
        add_style_keyboard_default,
        add_style_chart_default,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_label_h_1,
        remove_style_label_h_2,
        remove_style_label_h_3,
        remove_style_label_default,
        remove_style_button_apply,
        remove_style_button_default,
        remove_style_roller_default,
        remove_style_label_normal_right,
        remove_style_tabview_default,
        remove_style_tab_default,
        remove_style_textarea_default,
        remove_style_keyboard_default,
        remove_style_chart_default,
    };
    remove_style_funcs[styleIndex](obj);
}

