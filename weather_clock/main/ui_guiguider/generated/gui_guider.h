/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_main;
	bool screen_main_del;
	lv_obj_t *screen_main_img_1;
	lv_obj_t *screen_main_bar_humi;
	lv_obj_t *screen_main_img_2;
	lv_obj_t *screen_main_bar_tmp;
	lv_obj_t *screen_main_label_humi;
	lv_obj_t *screen_main_label_tmp;
	lv_obj_t *screen_main_animimg_1;
	lv_obj_t *screen_main_label_hour;
	lv_obj_t *screen_main_label_4;
	lv_obj_t *screen_main_label_minute;
	lv_obj_t *screen_main_label_date;
	lv_obj_t *screen_main_label_weather;
	lv_obj_t *screen_main_label_scroll;
	lv_obj_t *screen_main_img_weather;
	lv_obj_t *screen_main_label_position;
	lv_obj_t *screen_main_ddlist_city;
	lv_obj_t *screen_display_camera_data;
	bool screen_display_camera_data_del;
	lv_obj_t *screen_display_camera_data_img_display_camera;
	lv_obj_t *screen_display_camera_data_label_ax;
	lv_obj_t *screen_display_camera_data_label_ay;
	lv_obj_t *screen_display_camera_data_label_az;
	lv_obj_t *screen_display_camera_data_label_gx;
	lv_obj_t *screen_display_camera_data_label_gy;
	lv_obj_t *screen_display_camera_data_label_gz;
	lv_obj_t *screen_display_camera_data_label_pitch;
	lv_obj_t *screen_display_camera_data_label_4;
	lv_obj_t *screen_display_camera_data_label_6;
	lv_obj_t *screen_display_camera_data_label_roll;
	lv_obj_t *screen_display_camera_data_label_yaw;
	lv_obj_t *screen_display_camera_data_label_8;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen_main(lv_ui *ui);
void setup_scr_screen_display_camera_data(lv_ui *ui);
LV_IMG_DECLARE(_tem_alpha_29x29);
LV_IMG_DECLARE(_hum_alpha_21x23);
#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(screen_main_animimg_1space_man_10);
LV_IMG_DECLARE(screen_main_animimg_1space_man_13);
LV_IMG_DECLARE(screen_main_animimg_1space_man_21);
LV_IMG_DECLARE(screen_main_animimg_1space_man_22);
LV_IMG_DECLARE(screen_main_animimg_1space_man_26);
LV_IMG_DECLARE(screen_main_animimg_1space_man_28);
LV_IMG_DECLARE(screen_main_animimg_1space_man_29);
LV_IMG_DECLARE(screen_main_animimg_1space_man_32);
LV_IMG_DECLARE(screen_main_animimg_1space_man_33);
LV_IMG_DECLARE(screen_main_animimg_1space_man_35);
LV_IMG_DECLARE(screen_main_animimg_1space_man_36);
LV_IMG_DECLARE(screen_main_animimg_1space_man_38);
LV_IMG_DECLARE(screen_main_animimg_1space_man_39);
LV_IMG_DECLARE(screen_main_animimg_1space_man_4);
LV_IMG_DECLARE(screen_main_animimg_1space_man_8);
LV_IMG_DECLARE(_w10_alpha_54x53);
LV_IMG_DECLARE(_w0_alpha_96x96);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Acme_Regular_55)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_14)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_20)


#ifdef __cplusplus
}
#endif
#endif
