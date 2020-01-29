set (TEXT_PLAYER_LIB TextPlayer)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} )

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${TEXT_PLAYER_LIB} ${SOURCE_FILES})

install(FILES data.txt
  textplayer.sh
  DESTINATION ../build/)
