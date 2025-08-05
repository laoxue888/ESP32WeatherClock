#ifndef GET_WEATHER_H
#define GET_WEATHER_H

#include <time.h>
#include <sys/time.h>

#define FORECAST_DAY        3
#define REQUEST_INTERVAL    2  //  minutes
#define TEXT_LEN 22  
#define LOCATION "zhuhai" //地点
#define HOST "api.seniverse.com"  //网址
#define HTTP_PORT "80"
#define API_KEY "SxtrYSMFiKM8HYYuj" //API密钥
// #define LOCATION "chengdu" //地点
#define LANGUAGE "zh-Hans" // 简体中文
#define TEMPERATURE_UNIT "c"
#define RESPONSE_BODY_MAX_SIZE 1024  // 响应体最大长度
#define MAX_RETRY 10

static char response_body[RESPONSE_BODY_MAX_SIZE];  // 用于接收通过http响应体报文


// 天气字符最大为"雷阵雨伴有冰雹" 共计21, 某尾加\0 -> 22
typedef struct weather
{
    char text_day[FORECAST_DAY][TEXT_LEN];           // 白天天气（文本）
    char text_night[FORECAST_DAY][TEXT_LEN];         // 晚上天气（文本）
    uint8_t code_day[FORECAST_DAY];         // 白天天气（代码）
    uint8_t code_night[FORECAST_DAY];       // 晚上天气（代码）
    int8_t  degree_high[FORECAST_DAY];      // 最高气温
    int8_t  degree_low[FORECAST_DAY];       // 最低气温
    uint8_t humidity[FORECAST_DAY];         // 湿度 
    char city[TEXT_LEN];
}weather_t;

class GetWeather{
public:
    GetWeather();
    ~GetWeather();
    void cjsonParseXinzhiWeather(char *rdata);
    weather_t *getWeather(const char* city);//参考IDF官方案例重写一遍

private:
    const char *TAG = "GET_WEATHER";
    
};

#endif