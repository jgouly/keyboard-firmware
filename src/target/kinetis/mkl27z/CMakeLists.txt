add_library(target STATIC startup.cpp lpuart.cpp flashconfig.cpp vectors.cpp
                          ./third_party/usb_dev.c ./third_party/usb_mem.c
                          ./third_party/usb_desc.c ./third_party/usb_keyboard.c)
set(TARGET_LINKER_SCRIPT mkl27z256.ld)
target_link_libraries(target INTERFACE -Wl,--gc-sections -Os -mcpu=cortex-m0plus
  -mthumb -flto -Wl,-Map,link.map
  -T${CMAKE_CURRENT_LIST_DIR}/${TARGET_LINKER_SCRIPT})
