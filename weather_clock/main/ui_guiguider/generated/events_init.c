/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "esp_log.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_main_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_display_camera_data, guider_ui.screen_display_camera_data_del, &guider_ui.screen_main_del, setup_scr_screen_display_camera_data, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true, false);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_display_camera_data, guider_ui.screen_display_camera_data_del, &guider_ui.screen_main_del, setup_scr_screen_display_camera_data, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, true, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}


static void test_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        // char buf[32];
        uint16_t cityCode_;
        // lv_dropdown_get_selected_str(obj, buf, sizeof(buf));
        cityCode_ = lv_dropdown_get_selected(obj);
        cityCode = cityCode_;
        // LV_LOG_USER("Option: %s", buf);
        ESP_LOGI("lv_dropdown","Option: %d", cityCode_);

    }
    // ESP_LOGI("lv_dropdown","Option");
}


void events_init_screen_main (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_main, screen_main_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_main_ddlist_city, test_event_handler, LV_EVENT_ALL, NULL);
}

static void screen_display_camera_data_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {

        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_display_camera_data_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true, false);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_display_camera_data_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, true, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_display_camera_data (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_display_camera_data, screen_display_camera_data_event_handler, LV_EVENT_ALL, ui);
}




void events_init(lv_ui *ui)
{
    
}
