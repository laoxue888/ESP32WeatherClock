set(UI_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/ui_guiguider)

file(GLOB_RECURSE UI_SOURCES 
    ${UI_SOURCE_DIR}/custom/*.c 
    ${UI_SOURCE_DIR}/generated/*.c 
    ${UI_SOURCE_DIR}/generated/images/*.c
    ${UI_SOURCE_DIR}/weather_icons/*.c
    )

set(SOURCES 
            "application/application.cpp"
            "system_info/system_info.cpp"
            "settings/settings.cpp"
            "main.cpp"
            "wifi/wifi.cpp"
            "imu8658/imu8658.cpp"
            "ntp_time/ntp_time.cpp"
            "get_weather/get_weather.cpp"
            "ui_event/ui_event.cpp"
            ${UI_SOURCES}
            )

set(ui_include_dirs 
    ${UI_SOURCE_DIR}/custom
    ${UI_SOURCE_DIR}/generated
    ${UI_SOURCE_DIR}/generated/guider_customer_fonts
    ${UI_SOURCE_DIR}/generated/guider_fonts   
    )

# include header file
set(INCLUDE_DIRS 
                "." 
                "application" 
                "system_info" 
                "settings" 
                "wifi"  
                "imu8658"
                "ntp_time"
                "get_weather"
                "ui_event"
                ${ui_include_dirs}
                )

idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS ${INCLUDE_DIRS}
                    WHOLE_ARCHIVE
                    )

# 加入编译变量
target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_LVGL_H_INCLUDE_SIMPLE")
