cmake_minimum_required(VERSION 2.8.12)

project(firmware)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti -fno-exceptions")

include_directories(board/${BOARD})

add_subdirectory(board/${BOARD})

if (NOT TARGET)
  message(FATAL_ERROR "TARGET must be set!")
endif ()

add_subdirectory(src)
