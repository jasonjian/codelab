set (GREEDY_LIB Greedy)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${GREEDY_LIB} SHARED ${SOURCE_FILES})

target_link_libraries(${GREEDY_LIB})
