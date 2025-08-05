# # esp-idf/main/libmain.a(events_init.c.obj):(.literal.screen_add_chinese_data_event_handler+0x4): undefined reference to `guider_ui'
# #在这里写一个链接程序即可
# set(UI_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

# file(GLOB_RECURSE SOURCES 
#     ${UI_SOURCE_DIR}/custom/*.c 
#     ${UI_SOURCE_DIR}/generated/*.c 
#     ${UI_SOURCE_DIR}/generated/images/*.c
#     ${UI_SOURCE_DIR}/weather_icons/*.c
#     )

# set(include_dirs 
#     ${UI_SOURCE_DIR}/custom
#     ${UI_SOURCE_DIR}/generated
#     ${UI_SOURCE_DIR}/generated/guider_customer_fonts
#     ${UI_SOURCE_DIR}/generated/guider_fonts   
#     # ${CMAKE_CURRENT_LIST_DIR}/../../managed_components/lvgl__lvgl
#     # ${CMAKE_CURRENT_LIST_DIR}/../../managed_components/lvgl__lvgl/src/font  
#     )
# idf_component_register(SRCS ${SOURCES}
#                     INCLUDE_DIRS ${include_dirs}
#                     REQUIRES lvgl__lvgl
#                     )

# # 加入编译变量
# target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_LVGL_H_INCLUDE_SIMPLE")