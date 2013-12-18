
project(UTF8CPP_BUILDER CXX)
cmake_minimum_required(VERSION 2.8)

include(ExternalProject)

ExternalProject_Add(utf8cpp
    SVN_REPOSITORY http://svn.code.sf.net/p/utfcpp/code
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    TIMEOUT 10
)

set_target_properties(utf8cpp PROPERTIES EXCLUDE_FROM_ALL TRUE)

ExternalProject_Get_Property(utf8cpp source_dir)
set(UTF8CPP_INCLUDE_DIR "${source_dir}/v2_0/source" PARENT_SCOPE)
