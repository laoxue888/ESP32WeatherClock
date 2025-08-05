/*
 * @Author: your name
 * @Date: 2021-10-13 17:24:29
 * @LastEditTime: 2021-10-29 17:52:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \s3_lvgl_v7\components\adc\bsp_adc.h
 */

#ifndef _KSDIY_LVGL_PORT_
#define _KSDIY_LVGL_PORT_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"

#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "driver/i2c_master.h"

#ifdef __cplusplus
extern "C" {
#endif
void ksdiy_lvgl_port_init(void);
bool ksdiy_lvgl_lock(int timeout_ms);

void ksdiy_lvgl_unlock(void);

i2c_master_bus_handle_t *get_ksdiy_i2c_bus_handle();

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif