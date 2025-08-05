#ifndef UI_EVENT_H
#define UI_EVENT_H

#include "gui_guider.h"
#include <time.h>
#include <cstdio>
#include "camera.h"
#include "get_weather.h"
#include "imu8658.h"
#include "lvgl.h"
#include <stdio.h>
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

extern volatile uint16_t cityCode;

class UiEvent
{
public:
    UiEvent(/* args */);
    ~UiEvent();

    void setQMI8658(IMU8658 *imu8658_);

    bool updateUiTime(tm *timeinfo);
    bool updateUiCamera(bool cam_init_ok_);
    void setGuiguider(lv_ui *guider_ui);
    bool updateUiWeather(weather_t *weather_);
    bool updateUiIMU();
    bool updateUiWeatherIcon();
    void updateWeatherImg(int index);

private:
    lv_ui *guider_ui;
    tm *timeinfo=nullptr;
    lv_img_dsc_t img_dsc;
    camera_fb_t *camera_fb;
    bool cam_init_ok = false;
    const char week_data[7][4] = {"日", "一", "二", "三", "四", "五", "六"};
    bool second_flag = false;
    const char *TAG = "UiEvent";
    weather_t *weather_data;
    IMU8658 *imu8658 = nullptr;

    /*Add two data series*/
    lv_chart_series_t * ser1 = nullptr;
    lv_chart_series_t * ser2 = nullptr;


};

#endif