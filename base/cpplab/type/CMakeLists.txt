set (TYPE_LAB_LIB TypeLab)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${TYPE_LAB_LIB} SHARED ${SOURCE_FILES})

target_link_libraries(${TYPE_LAB_LIB} UserData)

install (TARGETS ${TYPE_LAB_LIB}  DESTINATION lib)
