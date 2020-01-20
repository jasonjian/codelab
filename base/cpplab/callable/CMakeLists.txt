set (CALLABLE_LIB Callable)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${CALLABLE_LIB} ${SOURCE_FILES})

target_link_libraries(${CALLABLE_LIB} gtest)
