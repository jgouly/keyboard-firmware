add_library(target STATIC startup.cpp vectors.cpp flashconfig.cpp)
set(TARGET_LINKER_SCRIPT mkl27z256.ld)
set(TARGET_FLAGS -mcpu=cortex-m0plus -mthumb -Os -fdata-sections
  -ffunction-sections -nostdlib -ffreestanding -nostartfiles)
target_link_libraries(target INTERFACE -Wl,--gc-sections -Os -mcpu=cortex-m0plus
  -mthumb -flto -Wl,-Map,link.map -nostdlib
  -T${CMAKE_CURRENT_LIST_DIR}/${TARGET_LINKER_SCRIPT})
target_compile_options(target PUBLIC ${TARGET_FLAGS})
