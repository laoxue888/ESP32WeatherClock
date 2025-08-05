#include "ui_event.h"
#include "lvgl.h"
#include "events_init.h"


UiEvent::UiEvent()
{
    img_dsc.header.reserved = 0;
    img_dsc.header.always_zero = 0;
    img_dsc.header.w = 96;
    img_dsc.header.h = 96;
    img_dsc.data_size = 96 * 96 * 2;
    img_dsc.header.cf = LV_IMG_CF_TRUE_COLOR; 

}

UiEvent::~UiEvent()
{

}

void UiEvent::setQMI8658(IMU8658 *imu8658_)
{
    if(imu8658_ == nullptr)
    {
        ESP_LOGE(TAG, "imu8658 is nullptr");
        return;
    }
    imu8658 = imu8658_;
}

bool UiEvent::updateUiIMU()
{
    char show_imu_text_ax[20];
    sprintf(show_imu_text_ax, "ax:%.6f", imu8658->acc.x);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_ax, show_imu_text_ax);

    char show_imu_text_ay[20];
    sprintf(show_imu_text_ay, "ay:%.6f", imu8658->acc.y);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_ay, show_imu_text_ay);

    char show_imu_text_az[20];
    sprintf(show_imu_text_az, "az:%.6f", imu8658->acc.z);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_az, show_imu_text_az);

    char show_imu_text_gx[20];
    sprintf(show_imu_text_gx, "gx:%.6f", imu8658->gyr.x);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_gx, show_imu_text_gx);

    char show_imu_text_gy[20];
    sprintf(show_imu_text_gy, "gy:%.6f", imu8658->gyr.y);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_gy, show_imu_text_gy);

    char show_imu_text_gz[20];
    sprintf(show_imu_text_gz, "gz:%.6f", imu8658->gyr.z);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_gz, show_imu_text_gz);

    char show_imu_text_pitch[20];
    sprintf(show_imu_text_pitch, "pitch=%.4f", imu8658->pitch);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_pitch, show_imu_text_pitch);

    char show_imu_text_roll[20];
    sprintf(show_imu_text_roll, "roll=%.4f", imu8658->roll);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_roll, show_imu_text_roll);

    char show_imu_text_yaw[20];
    sprintf(show_imu_text_yaw, "yaw:%.4f", imu8658->yaw);
    lv_label_set_text(guider_ui->screen_display_camera_data_label_yaw, show_imu_text_yaw);

    return true;

}

bool UiEvent::updateUiWeather(weather_t *weather_){
    if (guider_ui->screen_main == nullptr )
    {
        return false;
    }
    weather_data = weather_;
    
    //城市
    // lv_label_set_text(guider_ui->screen_main_label_position, weather_data->city);
    lv_obj_set_style_text_font(guider_ui->screen_main_ddlist_city, &lv_customer_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);

    //天气
    if(timeinfo != nullptr)
    {
        if (timeinfo->tm_hour >= 6 && timeinfo->tm_hour <= 18) //6:00 ~ 18:00
        {
            lv_label_set_text(guider_ui->screen_main_label_weather, weather_data->text_day[0]);           // 表示白天
            //更新图片
            updateUiWeatherIcon();
        }
        else
        {
            lv_label_set_text(guider_ui->screen_main_label_weather, weather_data->text_night[0]);           // 表示晚上
            //更新图片
            updateUiWeatherIcon();
        }
    }
    lv_obj_set_style_text_font(guider_ui->screen_main_label_weather, &lv_customer_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);

    //湿度
    char show_weather_hum[60];
    sprintf(show_weather_hum, "%d%%", weather_data->humidity[0]);
    lv_label_set_text(guider_ui->screen_main_label_humi, show_weather_hum);
    lv_bar_set_value(guider_ui->screen_main_bar_humi, weather_data->humidity[0], LV_ANIM_ON);

    //温度
    char show_weather_temp[60];
    int avg = (weather_data->degree_high[0] + weather_data->degree_low[0]) / 2;
    sprintf(show_weather_temp, "%d°C", avg);
    lv_label_set_text(guider_ui->screen_main_label_tmp, show_weather_temp);
    lv_bar_set_value(guider_ui->screen_main_bar_tmp, avg, LV_ANIM_ON);

    //更新滚动文字，最高最低温度、风向、风速
    char show_weather_long_text[224];
    sprintf(show_weather_long_text, "今日最高温度%d°C、最低温度%d°C、白天%s、晚上%s; 明日最高温度%d°C、最低温度%d°C、白天%s、晚上%s。", 
        weather_data->degree_high[0], weather_data->degree_low[0],
        weather_data->text_day[0], weather_data->text_night[0],
        weather_data->degree_high[1], weather_data->degree_low[1],
        weather_data->text_day[1], weather_data->text_night[1]);
    lv_label_set_text(guider_ui->screen_main_label_scroll, show_weather_long_text);
    lv_obj_set_style_text_font(guider_ui->screen_main_label_scroll, &lv_customer_font_SourceHanSerifSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);

    return true;
}

bool UiEvent::updateUiWeatherIcon()
{
    //天气
    if(timeinfo != nullptr)
    {
        if (timeinfo->tm_hour >= 6 && timeinfo->tm_hour <= 18) //6:00 ~ 18:00
        {
            lv_label_set_text(guider_ui->screen_main_label_weather, weather_data->text_day[0]);           // 表示白天
            //更新图片
            updateWeatherImg(weather_data->code_day[0]);
        }
        else
        {
            lv_label_set_text(guider_ui->screen_main_label_weather, weather_data->text_night[0]);           // 表示晚上
            //更新图片
            updateWeatherImg(weather_data->code_night[0]);
        }
    }
    return true;
}

bool UiEvent::updateUiTime(tm *timeinfo_){
    if (guider_ui->screen_main == nullptr )
    {
        return false;
    }

    timeinfo = timeinfo_;
    if(second_flag){
        lv_obj_add_flag(guider_ui->screen_main_label_4, LV_OBJ_FLAG_HIDDEN);
        second_flag=!second_flag;
    }else{
        lv_obj_clear_flag(guider_ui->screen_main_label_4, LV_OBJ_FLAG_HIDDEN);
        second_flag=!second_flag;
    }
    char show_time_text_min[60];
    sprintf(show_time_text_min, "%02d", timeinfo->tm_min);
    lv_label_set_text(guider_ui->screen_main_label_minute, show_time_text_min);

    char show_time_text_hour[60];
    sprintf(show_time_text_hour, "%02d", timeinfo->tm_hour);
    lv_label_set_text(guider_ui->screen_main_label_hour, show_time_text_hour); //2025年1月13日    周二
    

    char show_time_text_date[80];
    sprintf(show_time_text_date, "%4d年%d月%d日    周%s", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, week_data[timeinfo->tm_wday]);
    lv_label_set_text(guider_ui->screen_main_label_date, show_time_text_date);
    lv_obj_set_style_text_font(guider_ui->screen_main_label_date, &lv_customer_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);

    ESP_LOGI(TAG, "%4d年%d月%d日  周%d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_wday);

    return true;
}
bool UiEvent::updateUiCamera(bool cam_init_ok_)
{
    cam_init_ok = cam_init_ok_;
    if (guider_ui->screen_display_camera_data_img_display_camera != nullptr ) {
        if (cam_init_ok == true)
        {
            camera_fb = esp_camera_fb_get(); // 获取摄像头图片
            if (camera_fb != NULL)
            {
                img_dsc.data = camera_fb->buf; // 把摄像头图像的数据赋值
                // 更简单的刷新方式
                lv_img_cache_invalidate_src(&guider_ui->screen_display_camera_data_img_display_camera);
                lv_img_set_src(guider_ui->screen_display_camera_data_img_display_camera, &img_dsc);
                esp_camera_fb_return(camera_fb); // 返回图像 每次获取完图像都要返回一次
                // ESP_LOGI(TAG, "Camera capture ok...");
            }
        }
    }
    return true;
}
void UiEvent::setGuiguider(lv_ui *guider_ui_){
    guider_ui = guider_ui_;
}

void UiEvent::updateWeatherImg(int index)
{   
    if(index == 0)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w0);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w0.header.w, w0.header.h);
    }
    else if(index==4)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w4);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w4.header.w, w4.header.h);
    }
    else if(index==5)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w5);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w5.header.w, w5.header.h);
    }
    else if(index==6)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w6);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w6.header.w, w6.header.h);
    }
    else if(index==7)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w7);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w7.header.w, w7.header.h);
    }
    else if(index==8)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w8);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w8.header.w, w8.header.h);
    }
    else if(index==9)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w9);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w9.header.w, w9.header.h);
    }
    else if(index==10)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w10);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w10.header.w, w10.header.h);
    }
    else if(index==11)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w11);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w11.header.w, w11.header.h);
    }
    else if(index==12)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w12);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w12.header.w, w12.header.h);
    }
    else if(index==13)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w13);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w13.header.w, w13.header.h);
    }
    else if(index==14)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w14);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w14.header.w, w14.header.h);
    }
    else if(index==15)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w15);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w15.header.w, w15.header.h);
    }
    else if(index==16)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w16);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w16.header.w, w16.header.h);
    }
    else if(index==19)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w19);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w19.header.w, w19.header.h);
    }
    else if(index==20)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w20);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w20.header.w, w20.header.h);
    }
    else if(index==21)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w21);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w21.header.w, w21.header.h);
    }
    else if(index==22)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w22);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w22.header.w, w22.header.h);
    }
    else if(index==23)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w23);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w23.header.w, w23.header.h);
    }
    else if(index==24)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w24);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w24.header.w, w24.header.h);
    }
    else if(index==25)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w25);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w25.header.w, w25.header.h);
    }
    else if(index==26)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w26);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w26.header.w, w26.header.h);
    }
    else if(index==27)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w27);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w27.header.w, w27.header.h);
    }
    else if(index==28)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w28);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w28.header.w, w28.header.h);
    }
    else if(index==29)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w29);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w29.header.w, w29.header.h);
    }
    else if(index==30)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w30);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w30.header.w, w30.header.h);
    }
    else if(index==31)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w31);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w31.header.w, w31.header.h);
    }
    else if(index==32)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w32);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w32.header.w, w32.header.h);
    }
    else if(index==33)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w33);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w33.header.w, w33.header.h);
    }
    else if(index==34)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w34);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w34.header.w, w34.header.h);
    }
    else if(index==35)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w35);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w35.header.w, w35.header.h);
    }
    else if(index==36)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w36);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w36.header.w, w36.header.h);
    }
    else if(index==37)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w37);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w37.header.w, w37.header.h);
    }
    else if(index==38)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w38);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w38.header.w, w38.header.h);
    }
    else if(index==99)
    {
        lv_img_set_src(guider_ui->screen_main_img_weather, &w99);
        lv_obj_set_size(guider_ui->screen_main_img_weather, w99.header.w, w99.header.h);
    }
}
