# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(Embarcatech_Servomotor_PWM C CXX ASM)

pico_sdk_init()

add_executable(Embarcatech_Servomotor_PWM Embarcatech_Servomotor_PWM.c)

pico_set_program_name(Embarcatech_Servomotor_PWM "Embarcatech_Servomotor_PWM")
pico_set_program_version(Embarcatech_Servomotor_PWM "0.1")

pico_generate_pio_header(Embarcatech_Servomotor_PWM ${CMAKE_CURRENT_LIST_DIR}/ws2812b.pio)

pico_enable_stdio_uart(Embarcatech_Servomotor_PWM 0)
pico_enable_stdio_usb(Embarcatech_Servomotor_PWM 1)

target_link_libraries(Embarcatech_Servomotor_PWM 
        hardware_timer
        hardware_pwm
        hardware_gpio
        hardware_pio
        pico_stdlib
        hardware_pwm)

target_include_directories(Embarcatech_Servomotor_PWM PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Embarcatech_Servomotor_PWM)