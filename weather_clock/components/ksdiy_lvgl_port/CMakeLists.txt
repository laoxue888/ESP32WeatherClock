idf_component_register(SRCS "ksdiy_lvgl_port.c"
                    INCLUDE_DIRS "."
                    REQUIRES 
                    driver
                    lvgl__lvgl
                    espressif__esp_lcd_touch_cst816s
                    espressif__esp_lcd_touch
                    )
