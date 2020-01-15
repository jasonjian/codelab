set(SMART_PTR_LIB SmartPtr)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${SMART_PTR_LIB}  SHARED  ${SOURCE_FILES})

target_link_libraries( ${SMART_PTR_LIB} UserData)

install (TARGETS ${SMART_PTR_LIB} DESTINATION lib)



