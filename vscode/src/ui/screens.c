#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_roller_sv_select(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_roller_get_selected(ta);
            assignIntegerProperty(flowState, 0, 3, value, "Failed to assign Selected in Roller widget");
        }
    }
}

static void event_handler_cb_main_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 32, 3, value, "Failed to assign Checked state");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 32, 0, e);
    }
}

static void event_handler_cb_main_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 34, 3, value, "Failed to assign Checked state");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 34, 0, e);
    }
}

static void event_handler_cb_main_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 36, 0, e);
    }
}

static void event_handler_cb_main_slider_progress(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 38, 4, value, "Failed to assign Value in Slider widget");
        }
    }
}

static void event_handler_cb_main_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 39, 0, e);
    }
}

static void event_handler_cb_main_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 41, 0, e);
    }
}

static void event_handler_cb_unit_config_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_unit_config_label_unit_pv_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_unit_config_label_unit_pv_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_unit_config_label_unit_pv_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_unit_config_label_unit_pv_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_unit_config_label_unit_pv_10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_unit_config_button_unitconfig_apply(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 29, 4, value, "Failed to assign Checked state");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 29, 0, e);
    }
}

static void event_handler_cb_unit_config_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 31, 0, e);
    }
}

static void event_handler_cb_unit_config_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 33, 0, e);
    }
}

static void event_handler_cb_unit_config_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 35, 0, e);
    }
}

static void event_handler_cb_unit_config_obj9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 37, 0, e);
    }
}

static void event_handler_cb_unit_config_obj10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 39, 0, e);
    }
}

static void event_handler_cb_key_board_textarea_keyboard_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 0, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_key_board_obj11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 1, e);
    }
}

static void event_handler_cb_key_board_obj12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_key_board_obj13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_key_board_obj14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_key_board_obj15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 720, 1280);
    {
        lv_obj_t *parent_obj = obj;
        {
            // roller_sv_select
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.roller_sv_select = obj;
            lv_obj_set_pos(obj, 8, 367);
            lv_obj_set_size(obj, 316, 334);
            lv_roller_set_options(obj, "ID0\nID1\nID2\nID3\nID4\nID5", LV_ROLLER_MODE_INFINITE);
            lv_obj_add_event_cb(obj, event_handler_cb_main_roller_sv_select, LV_EVENT_ALL, flowState);
            add_style_roller_default(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_display_pv_1_main
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_1_main = obj;
            lv_obj_set_pos(obj, 350, 416);
            lv_obj_set_size(obj, 366, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_h_2(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // line_1
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.line_1 = obj;
            lv_obj_set_pos(obj, 10, 343);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 700, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            // line_2
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.line_2 = obj;
            lv_obj_set_pos(obj, 350, 557);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 360, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 370, 344);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_label_default(obj);
            lv_label_set_text(obj, "Run SV Select");
        }
        {
            // label_display_pv_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_1 = obj;
            lv_obj_set_pos(obj, 150, 829);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_display_pv_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_2 = obj;
            lv_obj_set_pos(obj, 150, 896);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_display_pv_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_3 = obj;
            lv_obj_set_pos(obj, 150, 965);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_display_pv_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_4 = obj;
            lv_obj_set_pos(obj, 150, 1038);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_display_pv_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_5 = obj;
            lv_obj_set_pos(obj, 150, 1107);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_1 = obj;
            lv_obj_set_pos(obj, 520, 830);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_2 = obj;
            lv_obj_set_pos(obj, 520, 897);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_3 = obj;
            lv_obj_set_pos(obj, 520, 966);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_4 = obj;
            lv_obj_set_pos(obj, 520, 1039);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_5 = obj;
            lv_obj_set_pos(obj, 520, 1108);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_title_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_1 = obj;
            lv_obj_set_pos(obj, 400, 829);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV1");
        }
        {
            // label_unit_pv_title_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_2 = obj;
            lv_obj_set_pos(obj, 400, 897);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV2");
        }
        {
            // label_unit_pv_title_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_3 = obj;
            lv_obj_set_pos(obj, 400, 966);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV3");
        }
        {
            // label_unit_pv_title_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_4 = obj;
            lv_obj_set_pos(obj, 400, 1039);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV4");
        }
        {
            // label_unit_pv_title_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_5 = obj;
            lv_obj_set_pos(obj, 400, 1108);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV5");
        }
        {
            // label_display_pv_title_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_title_1 = obj;
            lv_obj_set_pos(obj, 30, 829);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV1");
        }
        {
            // label_display_pv_title_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_title_2 = obj;
            lv_obj_set_pos(obj, 30, 897);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV2");
        }
        {
            // label_display_pv_title_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_title_3 = obj;
            lv_obj_set_pos(obj, 30, 966);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV3");
        }
        {
            // label_display_pv_title_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_title_4 = obj;
            lv_obj_set_pos(obj, 30, 1039);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV4");
        }
        {
            // label_display_pv_title_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_display_pv_title_5 = obj;
            lv_obj_set_pos(obj, 30, 1108);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV5");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 360, 745);
            lv_obj_set_size(obj, 360, LV_SIZE_CONTENT);
            add_style_label_normal_right(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Units");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 0, 745);
            lv_obj_set_size(obj, 360, LV_SIZE_CONTENT);
            add_style_label_normal_right(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Display");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 0, 1);
            lv_obj_set_size(obj, 350, LV_SIZE_CONTENT);
            add_style_label_h_3(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Control");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 150, 92);
            lv_obj_set_size(obj, 530, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_h_1(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // line_3
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.line_3 = obj;
            lv_obj_set_pos(obj, 10, 728);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 700, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            // line_4
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.line_4 = obj;
            lv_obj_set_pos(obj, 10, 1178);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 4);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 700, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 350, 574);
            lv_obj_set_size(obj, 180, 120);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj0, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj17 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 180, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 538, 574);
            lv_obj_set_size(obj, 180, 120);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj1, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj18 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 180, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 622, 1182);
            lv_obj_set_size(obj, 96, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj2, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj19 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // slider_progress
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider_progress = obj;
            lv_obj_set_pos(obj, 30, 280);
            lv_obj_set_size(obj, 660, 34);
            lv_slider_set_range(obj, 0, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_main_slider_progress, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 622, 2);
            lv_obj_set_size(obj, 96, 52);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj3, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj20 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 350, 15);
            lv_obj_set_size(obj, 251, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj4, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_label_default(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    {
        if (!(lv_obj_get_state(objects.roller_sv_select) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 0, 3, "Failed to evaluate Selected in Roller widget");
            int32_t cur_val = lv_roller_get_selected(objects.roller_sv_select);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.roller_sv_select;
                lv_roller_set_selected(objects.roller_sv_select, new_val, LV_ANIM_OFF);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_display_pv_1_main);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_display_pv_1_main;
            lv_label_set_text(objects.label_display_pv_1_main, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 6, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_display_pv_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_display_pv_1;
            lv_label_set_text(objects.label_display_pv_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_display_pv_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_display_pv_2;
            lv_label_set_text(objects.label_display_pv_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_display_pv_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_display_pv_3;
            lv_label_set_text(objects.label_display_pv_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_display_pv_4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_display_pv_4;
            lv_label_set_text(objects.label_display_pv_4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_display_pv_5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_display_pv_5;
            lv_label_set_text(objects.label_display_pv_5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 11, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_1;
            lv_label_set_text(objects.label_unit_pv_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_2;
            lv_label_set_text(objects.label_unit_pv_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 13, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_3;
            lv_label_set_text(objects.label_unit_pv_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 14, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_4;
            lv_label_set_text(objects.label_unit_pv_4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_5;
            lv_label_set_text(objects.label_unit_pv_5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 29, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj16);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj16;
            lv_label_set_text(objects.obj16, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 32, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj0, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj0;
            if (new_val) lv_obj_add_state(objects.obj0, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj0, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 33, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj17);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj17;
            lv_label_set_text(objects.obj17, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 34, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj1, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj1;
            if (new_val) lv_obj_add_state(objects.obj1, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj1, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 34, 4, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj1, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj1;
            if (new_val) lv_obj_add_state(objects.obj1, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj1, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 35, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj18);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj18;
            lv_label_set_text(objects.obj18, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 37, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj19);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj19;
            lv_label_set_text(objects.obj19, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 38, 3, "Failed to evaluate Max in Slider widget");
        int32_t cur_val = lv_slider_get_max_value(objects.slider_progress);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_progress;
            int16_t min = lv_slider_get_min_value(objects.slider_progress);
            int16_t max = new_val;
            if (min < max) {
                lv_slider_set_range(objects.slider_progress, min, max);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 38, 4, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_progress);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_progress;
            lv_slider_set_value(objects.slider_progress, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 40, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj20);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj20;
            lv_label_set_text(objects.obj20, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 41, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj4;
            lv_label_set_text(objects.obj4, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_unit_config() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.unit_config = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 720, 1280);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 620, 1178);
            lv_obj_set_size(obj, 96, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_obj5, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj21 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // label_unit_pv_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_6 = obj;
            lv_obj_set_pos(obj, 460, 2);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_label_unit_pv_6, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_7 = obj;
            lv_obj_set_pos(obj, 460, 239);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_label_unit_pv_7, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_8
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_8 = obj;
            lv_obj_set_pos(obj, 460, 473);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_label_unit_pv_8, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_9
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_9 = obj;
            lv_obj_set_pos(obj, 460, 707);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_label_unit_pv_9, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_10
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_10 = obj;
            lv_obj_set_pos(obj, 460, 941);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_label_unit_pv_10, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_title_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_6 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV1");
        }
        {
            // label_unit_pv_title_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_7 = obj;
            lv_obj_set_pos(obj, 0, 236);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV2");
        }
        {
            // label_unit_pv_title_8
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_8 = obj;
            lv_obj_set_pos(obj, 0, 470);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV3");
        }
        {
            // label_unit_pv_title_9
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_9 = obj;
            lv_obj_set_pos(obj, 0, 704);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV4");
        }
        {
            // label_unit_pv_title_10
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_title_10 = obj;
            lv_obj_set_pos(obj, 0, 938);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_default(obj);
            lv_label_set_text(obj, "PV5");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 10, 1188);
            lv_obj_set_size(obj, 360, LV_SIZE_CONTENT);
            add_style_label_h_3(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Units");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 10, 1170);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 700, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 10, 466);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 700, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 10, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 700, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 10, 700);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 700, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 10, 934);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 700, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            // label_unit_pv_11
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_11 = obj;
            lv_obj_set_pos(obj, 120, 0);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_12
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_12 = obj;
            lv_obj_set_pos(obj, 120, 237);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_13
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_13 = obj;
            lv_obj_set_pos(obj, 120, 471);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_14
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_14 = obj;
            lv_obj_set_pos(obj, 120, 704);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // label_unit_pv_15
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_unit_pv_15 = obj;
            lv_obj_set_pos(obj, 120, 939);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
            add_style_label_normal_right(obj);
            lv_label_set_text(obj, "");
        }
        {
            // chart_1
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.chart_1 = obj;
            lv_obj_set_pos(obj, 0, 54);
            lv_obj_set_size(obj, 610, 170);
        }
        {
            // chart_2
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.chart_2 = obj;
            lv_obj_set_pos(obj, 0, 291);
            lv_obj_set_size(obj, 610, 170);
        }
        {
            // chart_3
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.chart_3 = obj;
            lv_obj_set_pos(obj, 0, 523);
            lv_obj_set_size(obj, 610, 170);
        }
        {
            // chart_4
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.chart_4 = obj;
            lv_obj_set_pos(obj, 0, 759);
            lv_obj_set_size(obj, 610, 170);
        }
        {
            // chart_5
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.chart_5 = obj;
            lv_obj_set_pos(obj, 0, 993);
            lv_obj_set_size(obj, 610, 170);
        }
        {
            // button_unitconfig_apply
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_unitconfig_apply = obj;
            lv_obj_set_pos(obj, 514, 1179);
            lv_obj_set_size(obj, 96, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_button_unitconfig_apply, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_button_apply(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj22 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 622, 2);
            lv_obj_set_size(obj, 96, 52);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_obj6, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj23 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 96, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 622, 238);
            lv_obj_set_size(obj, 96, 52);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_obj7, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj24 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 96, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 620, 474);
            lv_obj_set_size(obj, 96, 52);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_obj8, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj25 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 96, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 618, 708);
            lv_obj_set_size(obj, 96, 52);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_obj9, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj26 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 96, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 620, 945);
            lv_obj_set_size(obj, 96, 52);
            lv_obj_add_event_cb(obj, event_handler_cb_unit_config_obj10, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj27 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 96, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    
    tick_screen_unit_config();
}

void tick_screen_unit_config() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj21);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj21;
            lv_label_set_text(objects.obj21, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_6;
            lv_label_set_text(objects.label_unit_pv_6, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 4, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_7;
            lv_label_set_text(objects.label_unit_pv_7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_8;
            lv_label_set_text(objects.label_unit_pv_8, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 6, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_9);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_9;
            lv_label_set_text(objects.label_unit_pv_9, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_10;
            lv_label_set_text(objects.label_unit_pv_10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 19, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_11);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_11;
            lv_label_set_text(objects.label_unit_pv_11, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 20, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_12);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_12;
            lv_label_set_text(objects.label_unit_pv_12, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 21, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_13);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_13;
            lv_label_set_text(objects.label_unit_pv_13, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_14;
            lv_label_set_text(objects.label_unit_pv_14, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 23, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_unit_pv_15);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_unit_pv_15;
            lv_label_set_text(objects.label_unit_pv_15, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 29, 4, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.button_unitconfig_apply, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.button_unitconfig_apply;
            if (new_val) lv_obj_add_state(objects.button_unitconfig_apply, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.button_unitconfig_apply, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 29, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.button_unitconfig_apply, LV_OBJ_FLAG_CLICKABLE);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.button_unitconfig_apply;
            if (new_val) lv_obj_add_flag(objects.button_unitconfig_apply, LV_OBJ_FLAG_CLICKABLE);
            else lv_obj_clear_flag(objects.button_unitconfig_apply, LV_OBJ_FLAG_CLICKABLE);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 30, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj22);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj22;
            lv_label_set_text(objects.obj22, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 32, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj23);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj23;
            lv_label_set_text(objects.obj23, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 34, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj24);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj24;
            lv_label_set_text(objects.obj24, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 36, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj25);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj25;
            lv_label_set_text(objects.obj25, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 38, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj26);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj26;
            lv_label_set_text(objects.obj26, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 40, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj27);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj27;
            lv_label_set_text(objects.obj27, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_key_board() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.key_board = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 720, 1280);
    {
        lv_obj_t *parent_obj = obj;
        {
            // textarea_keyboard_input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_keyboard_input = obj;
            lv_obj_set_pos(obj, 0, 102);
            lv_obj_set_size(obj, 720, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_key_board_textarea_keyboard_input, LV_EVENT_ALL, flowState);
            add_style_textarea_default(obj);
            lv_obj_set_style_text_font(obj, &ui_font_noto_sans_mono_180, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 0, 311);
            lv_obj_set_size(obj, 720, 708);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_key_board_obj11, LV_EVENT_ALL, flowState);
            add_style_keyboard_default(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 294, 3);
            lv_obj_set_size(obj, 300, LV_SIZE_CONTENT);
            lv_obj_add_event_cb(obj, event_handler_cb_key_board_obj12, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_label_normal_right(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Cancel");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 594, 1058);
            lv_obj_set_size(obj, 124, 83);
            lv_obj_add_event_cb(obj, event_handler_cb_key_board_obj13, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj28 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 96, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 275, 1060);
            lv_obj_set_size(obj, 300, LV_SIZE_CONTENT);
            lv_obj_add_event_cb(obj, event_handler_cb_key_board_obj14, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_label_normal_right(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Save");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 622, 3);
            lv_obj_set_size(obj, 96, 52);
            lv_obj_add_event_cb(obj, event_handler_cb_key_board_obj15, LV_EVENT_ALL, flowState);
            add_style_button_default(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj29 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 96, LV_SIZE_CONTENT);
                    add_style_label_default(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.obj11, objects.textarea_keyboard_input);
    
    tick_screen_key_board();
}

void tick_screen_key_board() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 0, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_keyboard_input);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_keyboard_input);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_keyboard_input;
            lv_textarea_set_text(objects.textarea_keyboard_input, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj28);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj28;
            lv_label_set_text(objects.obj28, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj29);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj29;
            lv_label_set_text(objects.obj29, new_val);
            tick_value_change_obj = NULL;
        }
    }
}


extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "Main", "UnitConfig", "KeyBoard" };
static const char *object_names[] = { "main", "unit_config", "key_board", "obj0", "obj1", "obj2", "obj3", "obj4", "obj5", "label_unit_pv_6", "label_unit_pv_7", "label_unit_pv_8", "label_unit_pv_9", "label_unit_pv_10", "button_unitconfig_apply", "obj6", "obj7", "obj8", "obj9", "obj10", "obj11", "obj12", "obj13", "obj14", "obj15", "roller_sv_select", "label_display_pv_1_main", "line_1", "line_2", "label_display_pv_1", "label_display_pv_2", "label_display_pv_3", "label_display_pv_4", "label_display_pv_5", "label_unit_pv_1", "label_unit_pv_2", "label_unit_pv_3", "label_unit_pv_4", "label_unit_pv_5", "label_unit_pv_title_1", "label_unit_pv_title_2", "label_unit_pv_title_3", "label_unit_pv_title_4", "label_unit_pv_title_5", "label_display_pv_title_1", "label_display_pv_title_2", "label_display_pv_title_3", "label_display_pv_title_4", "label_display_pv_title_5", "line_3", "line_4", "slider_progress", "obj16", "obj17", "obj18", "obj19", "obj20", "label_unit_pv_title_6", "label_unit_pv_title_7", "label_unit_pv_title_8", "label_unit_pv_title_9", "label_unit_pv_title_10", "label_unit_pv_11", "label_unit_pv_12", "label_unit_pv_13", "label_unit_pv_14", "label_unit_pv_15", "chart_1", "chart_2", "chart_3", "chart_4", "chart_5", "obj21", "obj22", "obj23", "obj24", "obj25", "obj26", "obj27", "textarea_keyboard_input", "obj28", "obj29" };
static const char *style_names[] = { "Label_H_1", "Label_H_2", "Label_H_3", "Label_Default", "Button_Apply", "Button_Default", "Roller_Default", "Label_Normal_Right", "Tabview_Default", "Tab_Default", "Textarea_Default", "Keyboard_Default", "Chart_Default" };


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_unit_config,
    tick_screen_key_board,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_unit_config();
    create_screen_key_board();
}
