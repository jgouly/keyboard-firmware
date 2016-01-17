set_global(TARGET "kinetis")
set_global(SUBTARGET "mkl27z")

include_directories(${PROJECT_SOURCE_DIR}/src/target/${TARGET})

include(${PROJECT_SOURCE_DIR}/src/target/${TARGET}/${SUBTARGET}/Flags.cmake)

set_global(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TARGET_FLAGS}")
set_global(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TARGET_FLAGS}")

include_directories(${PROJECT_SOURCE_DIR}/src/target/${TARGET})

add_library(board STATIC j6t.cpp)
