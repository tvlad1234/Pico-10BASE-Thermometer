cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
project(10BASE-Thermometer)
set(target_name 10BASE-Thermometer)

pico_sdk_init()

add_subdirectory(Pico-10BASE-T-Library)
add_subdirectory(pico-bmp085Driv)

add_executable(${target_name})

target_sources(${target_name} PRIVATE
    main.c
    )

target_link_libraries(${target_name} PRIVATE
    pico_stdlib
    hardware_pio
    hardware_irq
    pico_multicore
    10baset
    bmp085
    )

# enable usb output, disable uart output
pico_enable_stdio_usb(10BASE-Thermometer 0)
pico_enable_stdio_uart(10BASE-Thermometer 0)

pico_add_extra_outputs(${target_name})
