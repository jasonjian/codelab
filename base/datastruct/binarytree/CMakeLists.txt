SET(BINARY_TREE_LIB BinaryTree)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)
add_library(${BINARY_TREE_LIB} SHARED ${SOURCE_FILES})

find_library(BINARY_TREE_LIB BinaryTree )

target_link_libraries( ${BINARY_TREE_LIB}
  UserData)

install(TARGETS ${BINARY_TREE_LIB} DESTINATION lib)
install(FILES binarytree.hpp DESTINATION include)

target_include_directories(${BINARY_TREE_LIB}
  INTERFACE ${CMEKE_CURRENT_SOURCE_DIR})
