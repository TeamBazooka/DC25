SET(ARDUINO_1_5 true)
SET(PLATFORM_ARCH avr)
SET(ARDUINO_CPU atmega328)
SET(CMAKE_TOOLCHAIN_FILE arduino-cmake/cmake/ArduinoToolchain.cmake)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(DC25)
SET(TARGET_NAME DC25)

SET(ARDUINO_LIBRARIES_ROOT libraries)
SET(ARDUINO_DEFAULT_BOARD nano)
SET(ARDUINO_DEFAULT_PORT /dev/ttyUSB0)

generate_arduino_firmware(${TARGET_NAME}
  SRCS dc25.cpp buffer.cpp line_info.cpp RgbAnimations.cpp
  HDRS buffer.h line_info.h RgbAnimations.h)
