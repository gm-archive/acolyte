
project(GTEST_BUILDER C CXX)
cmake_minimum_required(VERSION 2.8)

include(ExternalProject)

ExternalProject_Add(googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk
    TIMEOUT 10
    CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY:PATH=
               -Dgtest_force_shared_crt=ON
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
    INSTALL_COMMAND ""
)

set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIR "${source_dir}/include" PARENT_SCOPE)

# ExternalProject_Get_Property(googletest cfg_intdir)


ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIBS_DIR "${binary_dir}")

message(STATUS ${GTEST_LIBS_DIR})
message(STATUS ${GTEST_LIBS_DIR}/${CMAKE_CFG_INTDIR}/${CMAKE_STATIC_LIBRARY_PREFIX}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX})

# add_subdirectory(src/googletest EXCLUDE_FROM_ALL)
add_library(gtest STATIC IMPORTED GLOBAL)
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION
    ${GTEST_LIBS_DIR}/${CMAKE_CFG_INTDIR}/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
)

add_library(gtest_main STATIC IMPORTED GLOBAL)
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION
    ${GTEST_LIBS_DIR}/${CMAKE_CFG_INTDIR}/${CMAKE_STATIC_LIBRARY_PREFIX}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
)

# CMAKE_CFG_INTDIR 



