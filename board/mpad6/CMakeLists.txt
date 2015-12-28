set(TARGET "kinetis" PARENT_SCOPE)
set(SUBTARGET "mkl27z" PARENT_SCOPE)

include_directories(${PROJECT_SOURCE_DIR}/src/target/kinetis)
add_library(board STATIC mpad6.cpp)
