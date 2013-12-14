
project(ACOLYTE_RT_TESTS)

add_executable(test_math "test_math.cpp")
add_dependencies(test_math googletest)

target_link_libraries(test_math gtest)
target_link_libraries(test_math gtest_main)

include_directories(${GTEST_INCLUDE_DIR})

message(STATUS ${ACOLYTE_RT_SOURCE_DIR})
message(STATUS ${GTEST_INCLUDE_DIR})

add_test(test_math test_math)
