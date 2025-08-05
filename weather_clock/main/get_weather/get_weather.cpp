#include "get_weather.h"
#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "esp_http_client.h"
#include "cJSON.h"

static weather_t weather;

GetWeather::GetWeather()
{
    // 构造函数
}

GetWeather::~GetWeather()
{
    // 析构函数
}

weather_t *GetWeather::getWeather(const char* city)
{
    char weather_url[256];
    sprintf(weather_url, "http://%s/v3/weather/daily.json?key=%s&location=%s&language=%s&unit=%s&start=0&days=3",
        HOST, API_KEY, city, LANGUAGE, TEMPERATURE_UNIT);
    // ESP_LOGI(TAG, "weather_url: %s", weather_url);

    int content_length = 0;
    //创建一个esp_http_client_config_t的实例（实例化对象），并配置HTTP-Client句柄
    esp_http_client_config_t http_client_cfg = {
        .url = weather_url,
    };
    
    esp_http_client_handle_t http_client_handle = esp_http_client_init(&http_client_cfg);  // 初始化http连接
    esp_http_client_set_method(http_client_handle, HTTP_METHOD_GET);                       // 向服务器发送get请求
    memset(&weather, 0, sizeof(weather_t));
    
    memset(&response_body, 0, sizeof(response_body));

    time_t now;
    struct tm *time_now;

    uint8_t i_try=0;

    while (i_try < MAX_RETRY)
    {
        ESP_LOGI(TAG, "Try %d", i_try);
        // 与目标主机创建连接，并且声明写入内容长度为0,打开连接，发送http请求头，形参write_len为发送内容数据长度
        esp_err_t err = esp_http_client_open(http_client_handle, 0);

        if (err != ESP_OK)
        {
            ESP_LOGE(TAG, "Failed to open HTTP connection: %s", esp_err_to_name(err));
            for (size_t i = 0; i < REQUEST_INTERVAL * 60; i++)
            {
                vTaskDelay(1000 / portTICK_PERIOD_MS);
            }
            i_try++;
            continue;
        }
        // 读取响应头报文               读取数据，自动处理掉响应头并返回接收包长度
        content_length = esp_http_client_fetch_headers(http_client_handle);
        if (content_length < 0 || content_length > RESPONSE_BODY_MAX_SIZE)  // 返回响应头报文长度太短太长都是问题
        {
            ESP_LOGE(TAG, "HTTP client fetch headers failed");
            for (size_t i = 0; i < REQUEST_INTERVAL * 60; i++)
            {
                vTaskDelay(1000 / portTICK_PERIOD_MS);
            }
            i_try++;
            continue;
        }

        if (esp_http_client_read_response(http_client_handle, response_body, RESPONSE_BODY_MAX_SIZE) < 0)
        {
            ESP_LOGE(TAG, "Failed to read response");
            for (size_t i = 0; i < REQUEST_INTERVAL * 60; i++)
            {
                vTaskDelay(1000 / portTICK_PERIOD_MS);
            }
            i_try++;
            continue;
        }

        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %lld",
                    esp_http_client_get_status_code(http_client_handle),     //获取响应状态信息
                    esp_http_client_get_content_length(http_client_handle)); //获取响应信息长度
        // printf("%s\n", response_body);

        cjsonParseXinzhiWeather(response_body);
        esp_http_client_close(http_client_handle);  // 断开连接
        memset(&response_body, 0, sizeof(response_body));
        
        return &weather;
    }
    return nullptr;
}

/**
* @brief 解析心知天气提供的JSON格式数据
*
* 解析JSON格式的天气数据，并将解析结果存储在weather_t结构体中。
*
* @param rdata 包含天气数据的JSON字符串
*/
void GetWeather::cjsonParseXinzhiWeather(char *rdata)
{
    cJSON *pJsonRoot = cJSON_Parse(rdata);//解析json字符串

    // 如果是json格式数据，则开始解析
    if (pJsonRoot == NULL)  
    {
        cJSON_Delete(pJsonRoot);
        return;
    }

    // 获取results数组内容
    cJSON *pResults = cJSON_GetObjectItem(pJsonRoot, "results");    
    if (pResults == NULL)
    {
        cJSON_Delete(pJsonRoot);
        return;
    }

    cJSON *pObject = cJSON_GetArrayItem(pResults, 0);   // 解析 results 数组的内容
    if (pObject == NULL)
    {
        cJSON_Delete(pJsonRoot);
        return;
    }

    // 解析 results -> location 数组元素内容
    cJSON *pLocation = cJSON_GetObjectItem(pObject, "location");
    if (pLocation == NULL)
    {
        cJSON_Delete(pJsonRoot);
        return;
    }

    // 解析 results -> daily 数组元素内容
    cJSON *pDaily = cJSON_GetObjectItem(pObject, "daily");
    if (pDaily == NULL)
    {
        cJSON_Delete(pJsonRoot);
        return;
    }
        
    memset(&weather, 0, sizeof(weather_t));
    // 获取城市
    strcpy(weather.city, cJSON_GetObjectItem(pLocation, "name")->valuestring);
    // 获取 daily 的数组长度(默认3天)
    int daily_size = cJSON_GetArraySize(pDaily);
    for (int i = 0; i < daily_size; i++)
    {
        cJSON *daily_elem = cJSON_GetArrayItem(pDaily, i);   // 从daily数组从取第i个元素
        if (daily_elem != NULL)      
        {
            /* 为简化代码, 不考虑解析失败情况(这里解析失败概率极低) */
            //! char*指针指向CJSON解析的字符串, pJsonRoot释放后, 指针指向错误内存
            // weather.text_day[i]     = cJSON_GetObjectItem(daily_elem, "text_day")->valuestring;
            // weather.text_night[i]   = cJSON_GetObjectItem(daily_elem, "text_night")->valuestring;
            strcpy(weather.text_day[i], cJSON_GetObjectItem(daily_elem, "text_day")->valuestring);
            strcpy(weather.text_night[i], cJSON_GetObjectItem(daily_elem, "text_night")->valuestring);
            weather.code_day[i]     = atoi(cJSON_GetObjectItem(daily_elem, "code_day")->valuestring);    // 白天天气（代码）atoi (表示 ascii to integer)是把字符串转换成整型数的一个函数，
            weather.code_night[i]   = atoi(cJSON_GetObjectItem(daily_elem, "code_night")->valuestring);  // 晚上天气（代码）
            weather.degree_high[i]  = atoi(cJSON_GetObjectItem(daily_elem, "high")->valuestring);        // 最高气温
            weather.degree_low[i]   = atoi(cJSON_GetObjectItem(daily_elem, "low")->valuestring);         // 最低气温
            weather.humidity[i]     = atoi(cJSON_GetObjectItem(daily_elem, "humidity")->valuestring);    // 湿度
        }
    }

}