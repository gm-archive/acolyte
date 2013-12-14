
project(ACOLYTE_RT_TESTS)

add_executable(test_math EXCLUDE_FROM_ALL "test_math.cpp")
add_dependencies(test_math googletest)

target_link_libraries(test_math gtest_main acolyte_rt)

include_directories(${GTEST_INCLUDE_DIR})

add_test("enigma-rt/math" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test_math)
