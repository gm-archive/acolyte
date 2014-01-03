
project(ACOLYTE_RT_TESTS C CXX)
cmake_minimum_required(VERSION 2.8.10)

set(ACOLYTE_RT_TESTS_SRCS
    "test_math.cpp"
)

add_executable(acolyte_rt_tests EXCLUDE_FROM_ALL ${ACOLYTE_RT_TESTS_SRCS})
add_dependencies(TESTS acolyte_rt_tests)
set_property(TARGET acolyte_rt_tests PROPERTY FOLDER ${FOLDER_TESTING})

include_directories(${GTEST_INCLUDE_DIR})
target_link_libraries(acolyte_rt_tests gtest gtest_main acolyte_rt)

add_test("acolyte-rt-tests" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/acolyte_rt_tests")
