
project(GTEST_BUILDER C CXX)
cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

ExternalProject_Add(googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk
    TIMEOUT 10
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
    INSTALL_COMMAND ""
)

set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

add_subdirectory(src/googletest EXCLUDE_FROM_ALL)

ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIR "${source_dir}/include" PARENT_SCOPE)

ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIBS_DIR "${gtest_BINARY_DIR}" PARENT_SCOPE)
