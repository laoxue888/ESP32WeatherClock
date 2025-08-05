#include "application.h"


static const char* const STATE_STRINGS[] = {
    "unknown",
    "starting",
    "configuring",
    "idle",
    "connecting",
    "listening",
    "speaking",
    "upgrading",
    "activating",
    "fatal_error",
    "invalid_state"
};

Application::Application() {
    wifi_board_ = new WifiBoard();
    ntp_time = new NTPTime();
    weather = new GetWeather();
    ui_event = new UiEvent();
}

Application::~Application() {
    if (wifi_board_ != nullptr) {
        delete wifi_board_;
        wifi_board_ = nullptr;
    }
    if (ntp_time != nullptr) {
        delete ntp_time;
        ntp_time = nullptr;
    }
    if (weather != nullptr) {
        delete weather;
        weather = nullptr;
    }
    if (imu8658 != nullptr) {
        delete imu8658;
        imu8658 = nullptr;
    }
    if (ui_event != nullptr) {}
    {
        delete ui_event;
        ui_event = nullptr;
    }
    
}


void Application::Start() {

    SetDeviceState(kDeviceStateStarting);

    ksdiy_lvgl_port_init();
    //初始化UI
    if (ksdiy_lvgl_lock(0))
    {
        setup_ui(guider_ui_);//初始化完guiguider_ui后，才可以使用相关的ui函数。
        ksdiy_lvgl_unlock();
    }
    i2c_bus_handle = get_ksdiy_i2c_bus_handle();
    imu8658 = new IMU8658(i2c_bus_handle);

    /* Wait for the network to be ready */
    wifi_board_->StartNetwork();
    ui_event->setGuiguider(guider_ui_);

    if (camera_init()==ESP_OK)
    {
        camera_fb = esp_camera_fb_get();
        esp_camera_fb_return(camera_fb);
        cam_init_ok = true;
        ESP_LOGI(TAG, "Camera init ok...");
    }else{
        ESP_LOGE(TAG, "Camera init failed...");
    }

    timeinfo = ntp_time->getTime();
    initUI();

    /* Start the main loop */
    xTaskCreate([](void* arg) {
        Application* app = (Application*)arg;
        app->updateUILoop();
        vTaskDelete(NULL);
    }, "update_ui_loop", 4096 * 4, this, 2, nullptr);

    xTaskCreate([](void* arg) {
        Application* app = (Application*)arg;
        app->updateTimeDataLoop();
        vTaskDelete(NULL);
    }, "update_time_loop", 4096, this, 2, nullptr);

    xTaskCreate([](void* arg) {
        Application* app = (Application*)arg;
        app->updateWeatherDataLoop();
        vTaskDelete(NULL);
    }, "update_weather_loop", 4096, this, 2, nullptr);

    SetDeviceState(kDeviceStateIdle);
}

void Application::initUI() {
    //init lvgl ui
    custom_init(guider_ui_);
    ui_event->setQMI8658(imu8658);
    
    
}

// The Main Loop 
void Application::updateUILoop() {
    
    uint8_t i_interval_time = 0;
    while (true)
    {
        ksdiy_lvgl_lock(0); // 锁定GUI，防止在更新UI时被打断.注意不要在多线程中同时使用，否则会打架
        ui_event->updateUiCamera(cam_init_ok);
        imu8658->updateIMUData();
        ui_event->updateUiIMU();

        if(i_interval_time % 20 == 0) // 每20次循环更新一次时间信息，大约1秒更新一次时间
        {
            ui_event->updateUiTime(timeinfo);
            if(weather_data != nullptr && is_updating_data == false)
            {
                ui_event->updateUiWeather(weather_data);
            }else{
                weather_t weather_data_none;
                char noneText[22] = "    ";
                strcpy(weather_data_none.city, noneText);
                weather_data_none.degree_low[0] = 0;
                weather_data_none.degree_high[0] = 0;
                weather_data_none.degree_low[1] = 0;
                weather_data_none.degree_high[1] = 0;
                weather_data_none.code_day[0] = 99;
                weather_data_none.code_night[0] = 99;
                weather_data_none.humidity[0] = 0;
                strcpy(weather_data_none.text_night[0], noneText);
                strcpy(weather_data_none.text_night[1], noneText);
                strcpy(weather_data_none.text_day[0], noneText);
                strcpy(weather_data_none.text_day[1], noneText);

                ui_event->updateUiWeather(&weather_data_none);
            }
            i_interval_time = 0;
        }
        i_interval_time++;
        ksdiy_lvgl_unlock();
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}

void Application::updateTimeDataLoop() {//
    while (1)
    {

        timeinfo = ntp_time->getTime();
        vTaskDelay(60000 / portTICK_PERIOD_MS);
    }
}

void Application::updateWeatherDataLoop() {//
    uint16_t i_interval = 0;
    uint16_t cityCode_before = cityCode;
    while (1)
    {
        is_updating_data = true;
        if(cityCode_before !=cityCode)
        {
            weather_data = weather->getWeather(cityStr[cityCode]);
            cityCode_before =cityCode;
            continue;
        }
        if(i_interval % (5*60) == 0 || weather_data == nullptr)
        {
            weather_data = weather->getWeather(cityStr[cityCode]);
            i_interval=0;
        }
        i_interval++;
        is_updating_data = false;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Application::SetDeviceState(DeviceState state) {
    if (device_state_ == state) {
        return;
    }
    device_state_ = state;
    ESP_LOGI(TAG, "STATE: %s", STATE_STRINGS[device_state_]);
}

void Application::SetGuiguider(lv_ui *guider_ui)
{
    guider_ui_ = guider_ui;
}

