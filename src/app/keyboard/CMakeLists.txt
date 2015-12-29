add_executable(keyboard.elf keyboard.cpp)
if(${TARGET} STREQUAL "host")
  set(TARGET_LIB target)
else()
  set(TARGET_LIB -Wl,-whole-archive target -Wl,-no-whole-archive)
endif()
target_link_libraries(keyboard.elf ${TARGET_LIB} board scan)
if (NOT "${CMAKE_OBJCOPY}" STREQUAL "CMAKE_OBJCOPY-NOTFOUND")
  add_custom_command(TARGET keyboard.elf POST_BUILD
    COMMAND
      ${CMAKE_OBJCOPY} -O binary -R .eeprom
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/keyboard.elf
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/keyboard.bin
    COMMENT "Creating keyboard.bin file")
endif()
