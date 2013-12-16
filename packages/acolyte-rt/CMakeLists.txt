
project(ACOLYTE_RT CXX)
cmake_minimum_required(VERSION 2.8)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_definitions (-std=c++11 -flto -Wall -Wextra -pedantic -Werror)
endif()

include_directories("include")

set(ACOLYTE_RT_HEADERS
    "include/art/buffer.hpp"
    "include/art/object.hpp"
    "include/art/property.hpp"
    "include/art/random.hpp"
    "include/art/real.hpp"
    "include/art/string.hpp"
    "include/art/variant.hpp"
    "include/art/vector.hpp"
)

set(ACOLYTE_RT_SRCS
    "src/object.cpp"
    "src/random.cpp"
    "src/real.cpp"
    "src/variant.cpp"
    "src/vector.cpp"
)

add_subdirectory(test)

add_library(acolyte_rt ${ACOLYTE_RT_SRCS} ${ACOLYTE_RT_HEADERS})
