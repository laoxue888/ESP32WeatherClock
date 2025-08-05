#ifndef NTP_TIME_H
#define NTP_TIME_H

// #define TAG "NTP_TIME"
static const char *TAG = "NTP_TIME";

class NTPTime {
public:
    NTPTime();
    ~NTPTime();

    bool isNetworkConnected();
    struct tm *getTime();

};

#endif