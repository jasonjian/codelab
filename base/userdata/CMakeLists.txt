set(USER_DATA_LIB UserData)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${USER_DATA_LIB} SHARED ${SOURCE_FILES})

target_link_libraries(${USER_DATA_LIB}
  )
