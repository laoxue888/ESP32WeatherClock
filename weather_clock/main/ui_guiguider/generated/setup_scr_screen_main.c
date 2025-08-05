/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_main(lv_ui *ui)
{
    //Write codes screen_main
    ui->screen_main = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_main, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_main, LV_SCROLLBAR_MODE_AUTO);

    //Write style for screen_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_img_1
    ui->screen_main_img_1 = lv_img_create(ui->screen_main);
    lv_obj_add_flag(ui->screen_main_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_main_img_1, &_tem_alpha_29x29);
    lv_img_set_pivot(ui->screen_main_img_1, 50,50);
    lv_img_set_angle(ui->screen_main_img_1, 0);
    lv_obj_set_pos(ui->screen_main_img_1, 5, 200);
    lv_obj_set_size(ui->screen_main_img_1, 29, 29);

    //Write style for screen_main_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_main_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_main_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_main_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_bar_humi
    ui->screen_main_bar_humi = lv_bar_create(ui->screen_main);
    lv_obj_set_style_anim_time(ui->screen_main_bar_humi, 1000, 0);
    lv_bar_set_mode(ui->screen_main_bar_humi, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_main_bar_humi, 0, 100);
    lv_bar_set_value(ui->screen_main_bar_humi, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_main_bar_humi, 40, 247);
    lv_obj_set_size(ui->screen_main_bar_humi, 69, 6);

    //Write style for screen_main_bar_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_bar_humi, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_bar_humi, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_bar_humi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_bar_humi, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_bar_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_main_bar_humi, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_bar_humi, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_bar_humi, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_bar_humi, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_bar_humi, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_main_img_2
    ui->screen_main_img_2 = lv_img_create(ui->screen_main);
    lv_obj_add_flag(ui->screen_main_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_main_img_2, &_hum_alpha_21x23);
    lv_img_set_pivot(ui->screen_main_img_2, 50,50);
    lv_img_set_angle(ui->screen_main_img_2, 0);
    lv_obj_set_pos(ui->screen_main_img_2, 9, 239);
    lv_obj_set_size(ui->screen_main_img_2, 21, 23);

    //Write style for screen_main_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_main_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_main_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_main_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_bar_tmp
    ui->screen_main_bar_tmp = lv_bar_create(ui->screen_main);
    lv_obj_set_style_anim_time(ui->screen_main_bar_tmp, 1000, 0);
    lv_bar_set_mode(ui->screen_main_bar_tmp, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_main_bar_tmp, -25, 50);
    lv_bar_set_value(ui->screen_main_bar_tmp, 25, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_main_bar_tmp, 40, 212);
    lv_obj_set_size(ui->screen_main_bar_tmp, 69, 6);

    //Write style for screen_main_bar_tmp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_bar_tmp, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_bar_tmp, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_bar_tmp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_bar_tmp, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_bar_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_main_bar_tmp, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_bar_tmp, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_bar_tmp, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_bar_tmp, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_bar_tmp, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_main_label_humi
    ui->screen_main_label_humi = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_humi, "30%");
    lv_label_set_long_mode(ui->screen_main_label_humi, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_humi, 106, 243);
    lv_obj_set_size(ui->screen_main_label_humi, 51, 14);

    //Write style for screen_main_label_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_humi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_humi, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_humi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_humi, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_humi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_label_tmp
    ui->screen_main_label_tmp = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_tmp, "25°C");
    lv_label_set_long_mode(ui->screen_main_label_tmp, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_tmp, 107, 209);
    lv_obj_set_size(ui->screen_main_label_tmp, 49, 13);

    //Write style for screen_main_label_tmp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_tmp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_tmp, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_tmp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_tmp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_tmp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_tmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_animimg_1
    ui->screen_main_animimg_1 = lv_animimg_create(ui->screen_main);
    lv_animimg_set_src(ui->screen_main_animimg_1, (const void **) screen_main_animimg_1_imgs, 15);
    lv_animimg_set_duration(ui->screen_main_animimg_1, 60*15);
    lv_animimg_set_repeat_count(ui->screen_main_animimg_1, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->screen_main_animimg_1);
    lv_obj_set_pos(ui->screen_main_animimg_1, 152, 197);
    lv_obj_set_size(ui->screen_main_animimg_1, 82, 77);

    //Write codes screen_main_label_hour
    ui->screen_main_label_hour = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_hour, "13");
    lv_label_set_long_mode(ui->screen_main_label_hour, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_hour, 34, 87);
    lv_obj_set_size(ui->screen_main_label_hour, 62, 46);

    //Write style for screen_main_label_hour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_hour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_hour, &lv_font_Acme_Regular_55, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_hour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_hour, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_hour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_label_4
    ui->screen_main_label_4 = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_4, ":");
    lv_label_set_long_mode(ui->screen_main_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_4, 103, 87);
    lv_obj_set_size(ui->screen_main_label_4, 17, 46);

    //Write style for screen_main_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_4, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_4, &lv_font_Acme_Regular_55, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_label_minute
    ui->screen_main_label_minute = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_minute, "24");
    lv_label_set_long_mode(ui->screen_main_label_minute, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_minute, 131, 87);
    lv_obj_set_size(ui->screen_main_label_minute, 69, 46);

    //Write style for screen_main_label_minute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_minute, lv_color_hex(0xffab00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_minute, &lv_font_Acme_Regular_55, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_minute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_minute, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_minute, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_label_date
    ui->screen_main_label_date = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_date, "2025年1月13日    周二");
    lv_label_set_long_mode(ui->screen_main_label_date, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_date, 17, 153);
    lv_obj_set_size(ui->screen_main_label_date, 209, 21);

    //Write style for screen_main_label_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_date, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_date, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_label_weather
    ui->screen_main_label_weather = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_weather, "多云");
    lv_label_set_long_mode(ui->screen_main_label_weather, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_weather, 96, 19);
    lv_obj_set_size(ui->screen_main_label_weather, 74, 18);

    //Write style for screen_main_label_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_weather, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_weather, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_weather, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_weather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_label_scroll
    ui->screen_main_label_scroll = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_scroll, "今日最高温度30°C、最低温度26°C、白天多云、晚上多云; 明日最高温度30°C、最低温度24°C、白天多云、晚上多云。");
    lv_label_set_long_mode(ui->screen_main_label_scroll, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_pos(ui->screen_main_label_scroll, 15, 48);
    lv_obj_set_size(ui->screen_main_label_scroll, 151, 15);

    //Write style for screen_main_label_scroll, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_scroll, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_scroll, &lv_font_SourceHanSerifSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_scroll, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_scroll, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_scroll, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_img_weather
    ui->screen_main_img_weather = lv_img_create(ui->screen_main);
    lv_obj_add_flag(ui->screen_main_img_weather, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_main_img_weather, &_w10_alpha_54x53);
    lv_img_set_pivot(ui->screen_main_img_weather, 50,50);
    lv_img_set_angle(ui->screen_main_img_weather, 0);
    lv_obj_set_pos(ui->screen_main_img_weather, 176, 17);
    lv_obj_set_size(ui->screen_main_img_weather, 54, 53);

    //Write style for screen_main_img_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_main_img_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_main_img_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_img_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_main_img_weather, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_label_position
    ui->screen_main_label_position = lv_label_create(ui->screen_main);
    lv_label_set_text(ui->screen_main_label_position, "北京");
    lv_label_set_long_mode(ui->screen_main_label_position, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_label_position, 17, 13);
    lv_obj_set_size(ui->screen_main_label_position, 74, 18);

    //Write style for screen_main_label_position, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_label_position, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_label_position, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_label_position, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_label_position, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_label_position, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_label_position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_ddlist_city
    ui->screen_main_ddlist_city = lv_dropdown_create(ui->screen_main);
    lv_dropdown_set_options(ui->screen_main_ddlist_city, "珠海\n北京\n深圳\n贵港\n上海");
    lv_dropdown_set_symbol(ui->screen_main_ddlist_city, NULL);
    lv_obj_set_pos(ui->screen_main_ddlist_city, 8, 10);
    lv_obj_set_size(ui->screen_main_ddlist_city, 82, 33);

    //Write style for screen_main_ddlist_city, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_main_ddlist_city, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_ddlist_city, &lv_customer_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_ddlist_city, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_main_ddlist_city, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_main_ddlist_city, 125, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_main_ddlist_city, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_main_ddlist_city, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_ddlist_city, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_ddlist_city, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_ddlist_city, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_ddlist_city, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_ddlist_city, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_ddlist_city, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_ddlist_city, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_ddlist_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_main_ddlist_city_extra_list_selected_checked
    static lv_style_t style_screen_main_ddlist_city_extra_list_selected_checked;
    ui_init_style(&style_screen_main_ddlist_city_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_main_ddlist_city_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_main_ddlist_city_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_main_ddlist_city_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_main_ddlist_city_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_main_ddlist_city_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_main_ddlist_city_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_main_ddlist_city_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_main_ddlist_city_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_main_ddlist_city), &style_screen_main_ddlist_city_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_main_ddlist_city_extra_list_main_default
    static lv_style_t style_screen_main_ddlist_city_extra_list_main_default;
    ui_init_style(&style_screen_main_ddlist_city_extra_list_main_default);

    lv_style_set_max_height(&style_screen_main_ddlist_city_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_main_ddlist_city_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_main_ddlist_city_extra_list_main_default, &lv_customer_font_SourceHanSerifSC_Regular_16);
    lv_style_set_text_opa(&style_screen_main_ddlist_city_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_main_ddlist_city_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_main_ddlist_city_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_main_ddlist_city_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_main_ddlist_city_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_main_ddlist_city_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_main_ddlist_city_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_main_ddlist_city_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_main_ddlist_city_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_main_ddlist_city), &style_screen_main_ddlist_city_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_main_ddlist_city_extra_list_scrollbar_default
    static lv_style_t style_screen_main_ddlist_city_extra_list_scrollbar_default;
    ui_init_style(&style_screen_main_ddlist_city_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_main_ddlist_city_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_main_ddlist_city_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_main_ddlist_city_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_screen_main_ddlist_city_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_main_ddlist_city), &style_screen_main_ddlist_city_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //The custom code of screen_main.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_main);

    //Init events for screen.
    events_init_screen_main(ui);
}
