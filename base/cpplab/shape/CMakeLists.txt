set (SHAPE_LIB Shape)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${SHAPE_LIB} SHARED ${SOURCE_FILES})

target_link_libraries(${SHAPE_LIB}
  gtest
  )
