# Pico-2W-2350-Embedded-Software-Project


# Pico 2W Dynamic LED Patterns
Bare-metal C firmware for Raspberry Pi Pico 2W featuring mathematically-generated LED timing patterns including sinusoidal breathing, acceleration curves, heartbeat simulation, Morse code, and pseudo-random sequences.

# Features

- Sinusoidal breathing effect using wave generation
- Dynamic acceleration and deceleration patterns
- Heartbeat simulation with double-pulse timing
- Morse code SOS pattern
- Pseudo-random timing sequences
- Direct CYW43 HAL control without RTOS

# Tech Stack

- MCU: RP2350 (ARM Cortex-M33)
- Toolchain: arm-none-eabi-gcc 13.2.1
- Build System: CMake + Make
- SDK: Pico SDK 2.2.0

# Quick Start

## Setup
Install dependencies
sudo apt install cmake gcc-arm-none-eabi ninja-build git

## Clone SDK
cd ~
git clone https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init --recursive

## Set environment variable
echo 'export PICO_SDK_PATH=~/pico-sdk' >> ~/.bashrc
source ~/.bashrc

## Build firmware
mkdir build && cd build
cmake ..
make

## Flash to device (hold BOOTSEL button, connect USB, then release)
cp led_patterns.uf2 /media/$USER/RPI-RP2/


# Project Structure

.
├── CMakeLists.txt
├── pico_sdk_import.cmake
├── main.c
└── build/


# Performance

- Binary Size: ~80KB
- RAM Usage: <4KB
- Build Time: 10-60 seconds

# Learning Outcomes

- Bare-metal embedded C programming
- Cross-compilation for ARM Cortex-M architecture
- CMake build system configuration
- Hardware abstraction layer interaction
- Algorithm implementation in resource-constrained environments

  
Built for learning embedded development workflows using command-line tools.
