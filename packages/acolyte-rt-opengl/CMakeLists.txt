
project (ACOLYTE_RT_OPENGL CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    LIST (APPEND CMAKE_CXX_FLAGS "-std=c++11 -flto -Wall -Wextra -pedantic -Werror")
endif ()

include_directories ("${ACOLYTE_RT_SOURCE_DIR}/include")

file (GLOB ACOLYTE_RT_OPENGL_SRCS "src/*.cpp")

add_library (acolyte_rt_opengl ${ACOLYTE_RT_OPENGL_SRCS})
