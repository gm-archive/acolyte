
project(ACOLYTE_RT_TESTS C CXX)
cmake_minimum_required(VERSION 2.8)

set(ACOLYTE_RT_TESTS_SRCS
    "test_math.cpp"
)

add_definitions(-std=c++11 -pthread)

add_executable(acolyte_rt_tests EXCLUDE_FROM_ALL ${ACOLYTE_RT_TESTS_SRCS})
add_dependencies(tests acolyte_rt_tests)

include_directories(${GTEST_INCLUDE_DIR})
target_link_libraries(acolyte_rt_tests gtest gtest_main acolyte_rt pthread)

add_test("acolyte-rt-tests" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/acolyte_rt_tests")
