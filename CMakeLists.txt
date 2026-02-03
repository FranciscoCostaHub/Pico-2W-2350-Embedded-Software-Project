cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK TOOL, the file must be added to the local directory
include(pico_sdk_import.cmake)

set(PICO_BOARD pico2_w CACHE STRING "Board type")
set(PICO_PLATFORM rp2350 CACHE STRING "Platform")


project(smart_blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initializes SDK tool
pico_sdk_init()

add_executable(smart_blink smart_blink.c)

# Pull in pico_stdlib and cyw43 for the internal led
target_link_libraries(smart_blink
    pico_stdlib
    pico_cyw43_arch_none
)

# Output files creation
pico_add_extra_outputs(smart_blink)
