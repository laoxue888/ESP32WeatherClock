# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

option(HOST_BACKUP "Backup to the host server" ON) # ON or OFF

if(HOST_BACKUP)
    #备份到宿主机: 要清理一次运行后再运行编译后才可以实现备份
    set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    set(SAVE_DIR /mnt/hgfs/ESP32WeatherClock/weather_clock)

    execute_process(COMMAND rm -rf ${SAVE_DIR}/.vscode)
    execute_process(COMMAND rsync -av ${PROJECT_DIR}/.vscode ${SAVE_DIR})

    execute_process(COMMAND rm -rf ${SAVE_DIR}/main)
    execute_process(COMMAND rsync -av ${PROJECT_DIR}/main ${SAVE_DIR})

    execute_process(COMMAND rm -rf ${SAVE_DIR}/CMakeLists.txt)
    execute_process(COMMAND rsync -av ${PROJECT_DIR}/CMakeLists.txt ${SAVE_DIR})

    execute_process(COMMAND rm -rf ${SAVE_DIR}/sdkconfig)
    execute_process(COMMAND rsync -av ${PROJECT_DIR}/sdkconfig ${SAVE_DIR})

    execute_process(COMMAND rm -rf ${SAVE_DIR}/sdkconfig.defaults)
    execute_process(COMMAND rsync -av ${PROJECT_DIR}/sdkconfig.defaults ${SAVE_DIR})

    execute_process(COMMAND rm -rf ${SAVE_DIR}/README.md)
    execute_process(COMMAND rsync -av ${PROJECT_DIR}/README.md ${SAVE_DIR})

    execute_process(COMMAND rm -rf ${SAVE_DIR}/partitions.csv)
    execute_process(COMMAND rsync -av ${PROJECT_DIR}/partitions.csv ${SAVE_DIR})

    execute_process(COMMAND rm -rf ${SAVE_DIR}/components)
    execute_process(COMMAND rsync -av ${PROJECT_DIR}/components ${SAVE_DIR})

    # execute_process(COMMAND rm -rf ${SAVE_DIR}/docs)
    # execute_process(COMMAND rsync -av ${PROJECT_DIR}/docs ${SAVE_DIR})
endif()

# Add this line to disable the specific warning
add_compile_options(-Wno-missing-field-initializers)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(weather_clock)
