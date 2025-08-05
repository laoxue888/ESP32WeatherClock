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



void setup_scr_screen_display_camera_data(lv_ui *ui)
{
    //Write codes screen_display_camera_data
    ui->screen_display_camera_data = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_display_camera_data, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_display_camera_data, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_display_camera_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_img_display_camera
    ui->screen_display_camera_data_img_display_camera = lv_img_create(ui->screen_display_camera_data);
    lv_obj_add_flag(ui->screen_display_camera_data_img_display_camera, LV_OBJ_FLAG_CLICKABLE);
    // lv_img_set_src(ui->screen_display_camera_data_img_display_camera, &_w0_alpha_96x96);
    lv_img_set_pivot(ui->screen_display_camera_data_img_display_camera, 50,50);
    lv_img_set_angle(ui->screen_display_camera_data_img_display_camera, 0);
    lv_obj_set_pos(ui->screen_display_camera_data_img_display_camera, 14, 30);
    lv_obj_set_size(ui->screen_display_camera_data_img_display_camera, 96, 96);

    //Write style for screen_display_camera_data_img_display_camera, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_display_camera_data_img_display_camera, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_display_camera_data_img_display_camera, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_display_camera_data_img_display_camera, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_display_camera_data_img_display_camera, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_ax
    ui->screen_display_camera_data_label_ax = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_ax, "ax: -0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_ax, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_ax, 123, 9);
    lv_obj_set_size(ui->screen_display_camera_data_label_ax, 110, 15);

    //Write style for screen_display_camera_data_label_ax, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_ax, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_ax, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_ax, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_ax, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_ax, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_ay
    ui->screen_display_camera_data_label_ay = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_ay, "ay: -0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_ay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_ay, 123, 32);
    lv_obj_set_size(ui->screen_display_camera_data_label_ay, 110, 15);

    //Write style for screen_display_camera_data_label_ay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_ay, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_ay, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_ay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_ay, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_ay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_az
    ui->screen_display_camera_data_label_az = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_az, "az: -0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_az, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_az, 123, 55);
    lv_obj_set_size(ui->screen_display_camera_data_label_az, 110, 15);

    //Write style for screen_display_camera_data_label_az, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_az, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_az, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_az, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_az, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_az, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_gx
    ui->screen_display_camera_data_label_gx = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_gx, "gx: -0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_gx, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_gx, 123, 78);
    lv_obj_set_size(ui->screen_display_camera_data_label_gx, 110, 16);

    //Write style for screen_display_camera_data_label_gx, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_gx, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_gx, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_gx, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_gx, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_gx, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_gy
    ui->screen_display_camera_data_label_gy = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_gy, "gy: -0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_gy, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_gy, 123, 101);
    lv_obj_set_size(ui->screen_display_camera_data_label_gy, 110, 16);

    //Write style for screen_display_camera_data_label_gy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_gy, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_gy, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_gy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_gy, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_gy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_gz
    ui->screen_display_camera_data_label_gz = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_gz, "gz: -0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_gz, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_gz, 123, 124);
    lv_obj_set_size(ui->screen_display_camera_data_label_gz, 109, 16);

    //Write style for screen_display_camera_data_label_gz, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_gz, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_gz, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_gz, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_gz, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_gz, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_pitch
    ui->screen_display_camera_data_label_pitch = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_pitch, "pitch=-0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_pitch, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_pitch, 69, 165);
    lv_obj_set_size(ui->screen_display_camera_data_label_pitch, 166, 20);

    //Write style for screen_display_camera_data_label_pitch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_pitch, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_pitch, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_pitch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_pitch, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_4
    ui->screen_display_camera_data_label_4 = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_4, "俯仰角");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_4, 1, 165);
    lv_obj_set_size(ui->screen_display_camera_data_label_4, 66, 20);

    //Write style for screen_display_camera_data_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_4, &lv_font_SourceHanSerifSC_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_6
    ui->screen_display_camera_data_label_6 = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_6, "横滚角");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_6, 1, 197);
    lv_obj_set_size(ui->screen_display_camera_data_label_6, 66, 20);

    //Write style for screen_display_camera_data_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_6, &lv_font_SourceHanSerifSC_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_roll
    ui->screen_display_camera_data_label_roll = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_roll, "roll=-0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_roll, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_roll, 69, 197);
    lv_obj_set_size(ui->screen_display_camera_data_label_roll, 166, 20);

    //Write style for screen_display_camera_data_label_roll, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_roll, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_roll, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_roll, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_roll, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_yaw
    ui->screen_display_camera_data_label_yaw = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_yaw, "yaw=-0.999999");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_yaw, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_yaw, 69, 229);
    lv_obj_set_size(ui->screen_display_camera_data_label_yaw, 166, 20);

    //Write style for screen_display_camera_data_label_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_yaw, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_yaw, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_yaw, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_display_camera_data_label_8
    ui->screen_display_camera_data_label_8 = lv_label_create(ui->screen_display_camera_data);
    lv_label_set_text(ui->screen_display_camera_data_label_8, "偏航角");
    lv_label_set_long_mode(ui->screen_display_camera_data_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_display_camera_data_label_8, 1, 229);
    lv_obj_set_size(ui->screen_display_camera_data_label_8, 66, 20);

    //Write style for screen_display_camera_data_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_display_camera_data_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_display_camera_data_label_8, &lv_font_SourceHanSerifSC_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_display_camera_data_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_display_camera_data_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_display_camera_data_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_display_camera_data.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_display_camera_data);

    //Init events for screen.
    events_init_screen_display_camera_data(ui);
}
