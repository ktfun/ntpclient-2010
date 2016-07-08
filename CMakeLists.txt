cmake_minimum_required(VERSION 2.8)

SET(CMAKE_C_COMPILER  arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
SET(CMAKE_ASM_COMPILER arm-linux-gnueabihf-gcc)

set(LIB_SRC iwlib.c iwlib.h iwlib-private.h wireless.h)
add_library(libiw ${LIB_SRC})
set_target_properties(libiw PROPERTIES OUTPUT_NAME "iw")

