
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_math "test_math.cpp")
add_dependencies(test_math googletest)

add_test(test_math test_math)
