cmake_minimum_required(VERSION 2.8.12)

project(firmware)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti -fno-exceptions -g")

macro(set_global var val)
  set(${var} ${val})
  set(${var} ${val} PARENT_SCOPE)
endmacro()

include_directories(include)
include_directories(board/${BOARD})

add_subdirectory(board/${BOARD})

if (NOT TARGET)
  message(FATAL_ERROR "TARGET must be set!")
endif ()
include_directories(src/target/${TARGET})

add_subdirectory(src)
