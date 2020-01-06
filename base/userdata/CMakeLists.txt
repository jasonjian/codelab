set(USER_DATA_LIB UserData)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} source_files)
add_library(${USER_DATA_LIB} SHARED ${source_files})
