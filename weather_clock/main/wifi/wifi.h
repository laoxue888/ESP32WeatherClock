#ifndef WIFI_BOARD_H
#define WIFI_BOARD_H

// extern volatile bool is_wifi_connected;

class WifiBoard{
protected:
    bool wifi_config_mode_ = false;
    void EnterWifiConfigMode();
    // virtual std::string GetBoardJson() override;

public:
    WifiBoard();
    void StartNetwork();
    void SetPowerSaveMode(bool enabled) ;
    void ResetWifiConfiguration();
private:
    const char *TAG = "WifiBoard";
};

#endif // WIFI_BOARD_H
