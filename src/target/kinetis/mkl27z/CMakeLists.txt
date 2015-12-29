add_library(target STATIC startup.cpp lpuart.cpp flashconfig.cpp vectors.cpp)
set(TARGET_LINKER_SCRIPT mkl27z256.ld)
target_link_libraries(target INTERFACE -Wl,--gc-sections -Os -mcpu=cortex-m0plus
  -mthumb -flto -Wl,-Map,link.map -nostdlib
  -T${CMAKE_CURRENT_LIST_DIR}/${TARGET_LINKER_SCRIPT})
