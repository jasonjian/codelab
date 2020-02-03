set (PRACTICE_LIB Practice)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${PRACTICE_LIB} SHARED ${SOURCE_FILES})
target_link_libraries(${PRACTICE_LIB})
