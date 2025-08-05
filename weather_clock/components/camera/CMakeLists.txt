idf_component_register(SRCS "camera.c"
                    INCLUDE_DIRS "."
                    REQUIRES 
                    driver
                    espressif__esp32-camera
                    )
