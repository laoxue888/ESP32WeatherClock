#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <freertos/FreeRTOS.h>
#include <freertos/event_groups.h>
#include <freertos/task.h>

#include <cstring>
#include <esp_log.h>
#include <cJSON.h>
#include <driver/gpio.h>
#include "ksdiy_lvgl_port.h"
#include "camera.h"
#include "driver/i2c_master.h"
#include "gui_guider.h"
#include <string>
#include <mutex>
#include <list>
#include "wifi.h"
#include "gui_guider.h"
#include "get_weather.h"
#include "imu8658.h"
#include "ntp_time.h"
#include "ui_event.h"
#include <queue>


#if CONFIG_USE_AUDIO_PROCESSING
#include "wake_word_detect.h"
#include "audio_processor.h"
#endif

#define SCHEDULE_EVENT (1 << 0)
#define AUDIO_INPUT_READY_EVENT (1 << 1)
#define AUDIO_OUTPUT_READY_EVENT (1 << 2)

enum DeviceState {
    kDeviceStateUnknown,
    kDeviceStateStarting,
    kDeviceStateWifiConfiguring,
    kDeviceStateIdle,
    kDeviceStateConnecting,
    kDeviceStateListening,
    kDeviceStateSpeaking,
    kDeviceStateUpgrading,
    kDeviceStateActivating,
    kDeviceStateFatalError
};

#define OPUS_FRAME_DURATION_MS 60

extern volatile uint16_t cityCode;

class Application {
public:
    static Application& GetInstance() {
        static Application instance;
        return instance;
    }
    // 删除拷贝构造函数和赋值运算符
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    void Start();
    DeviceState GetDeviceState() const { return device_state_; }
    void SetDeviceState(DeviceState state);
    void SetGuiguider(lv_ui *guider_ui);


private:
    Application();
    ~Application();
    volatile DeviceState device_state_ = kDeviceStateUnknown;
    WifiBoard *wifi_board_ = nullptr;
    lv_ui *guider_ui_;
    camera_fb_t *camera_fb;
    bool cam_init_ok = false;
    void updateUILoop();
    void updateTimeDataLoop();
    void updateWeatherDataLoop();


    i2c_master_bus_handle_t *i2c_bus_handle = nullptr;
    IMU8658 *imu8658 = nullptr;
    NTPTime *ntp_time = nullptr;
    bool is_update_local_time = false;
    tm *timeinfo=nullptr;
    GetWeather *weather = nullptr;
    weather_t *weather_data = nullptr;
    UiEvent *ui_event = nullptr;
    bool is_updating_data = false;

    const char *TAG = "Application";

    void initUI(void);

    // std::queue<tm> timeinfoQueue;  // 创建一个存储int类型的队列
    const char cityStr[5][10] = {"zhuhai", "beijing", "shenzhen", "guigang", "shanghai"};

public:
    // static void test_event(lv_event_t * event);
};

#endif // _APPLICATION_H_
