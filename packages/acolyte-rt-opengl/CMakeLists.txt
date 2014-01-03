
project(ACOLYTE_RT_OPENGL CXX)
cmake_minimum_required(VERSION 2.8.10)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_definitions(-std=c++11 -flto -Wall -Wextra -pedantic -Werror)
endif()

include_directories("include")
include_directories("${ACOLYTE_RT_SOURCE_DIR}/include")

set(ACOLYTE_RT_OPENGL_HEADERS
    "include/art/shader.hpp"
)

set(ACOLYTE_RT_OPENGL_SRCS
    "src/shader.cpp"
)

add_library (acolyte_rt_opengl ${ACOLYTE_RT_OPENGL_SRCS} ${ACOLYTE_RT_OPENGL_HEADERS})
