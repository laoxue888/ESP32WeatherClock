#include "ntp_time.h"

#include <esp_netif.h>
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
#include "esp_sntp.h"

static struct tm timeinfo;

NTPTime::NTPTime() {
    // Constructor implementation
}

NTPTime::~NTPTime() {
    // Destructor implementation
}

struct tm *NTPTime::getTime() {
    // Implementation to get the current time from NTP server and return it as a struct tm pointer
    time_t now;
    if(isNetworkConnected())
    {
        // ESP_LOGI(TAG, "Network is connected");
        esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);    // 设置单播模式
        // esp_sntp_setservername(0, "cn.ntp.org.cn");	    // 设置访问服务器
        // esp_sntp_setservername(1, "ntp1.aliyun.com");
        // esp_sntp_setservername(2, "210.72.145.44");     // 国家授时中心服务器 IP 地址
        esp_sntp_setservername(0, "ntp.aliyun.com");
        esp_sntp_setservername(1, "210.72.145.44"); // 国家授时中心服务器 IP 地址 https://blog.csdn.net/sjzsel/article/details/122453509

        setenv("TZ", "CST-8", 1);                   //东八区
        esp_sntp_init();                                //初始化

        // 延时等待SNTP初始化完成
        do {
            vTaskDelay(100 / portTICK_PERIOD_MS);
        } while (sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET);

        // 成功获取网络时间后停止NTP请求，不然设备重启后会造成获取网络时间失败的现象
        // 大概是服务器时根据心跳时间来删除客户端的，如果不是stop结束的客户端，下次连接服务器时就会出错
        esp_sntp_stop();

        time(&now);                         // 获取网络时间, 64bit的秒计数     
        tzset();                            // 更新本地C库时间
        localtime_r(&now, &timeinfo);       // 转换成具体的时间参数
        return &timeinfo;
    }else{
        // ESP_LOGI(TAG, "Network is not connected");
    }
    return nullptr; // Placeholder, replace with actual implementation
}

bool NTPTime::isNetworkConnected() {
    // Implementation to check if the network is connected
    esp_netif_t *netif = esp_netif_get_default_netif();
    if (netif == NULL) {
        return false;
    }
    return esp_netif_is_netif_up(netif);
}