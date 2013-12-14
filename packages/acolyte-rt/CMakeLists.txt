
project (ACOLYTE_RT CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_definitions (-std=c++11 -flto -Wall -Wextra -pedantic -Werror)
endif ()

include_directories ("include")

file (GLOB ACOLYTE_RT_SRCS "src/*.cpp")
file (GLOB ACOLYTE_RT_HEADERS "include/**.hpp")

add_library (acolyte_rt ${ACOLYTE_RT_SRCS} ${ACOLYTE_RT_HEADERS})
