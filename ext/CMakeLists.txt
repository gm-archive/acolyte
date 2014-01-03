
add_subdirectory(gtest)
add_subdirectory(utf8cpp)

set_property(TARGET googletest utf8cpp PROPERTY FOLDER ${FOLDER_EXTERNAL})

set(GTEST_INCLUDE_DIR "${GTEST_INCLUDE_DIR}" PARENT_SCOPE)
set(UTF8CPP_INCLUDE_DIR "${UTF8CPP_INCLUDE_DIR}" PARENT_SCOPE)
