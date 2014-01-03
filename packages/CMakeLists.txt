
add_subdirectory(acolyte-rt)
add_subdirectory(acolyte-rt-opengl)

set_property(TARGET acolyte_rt acolyte_rt_opengl PROPERTY FOLDER ${FOLDER_PACKAGES})
