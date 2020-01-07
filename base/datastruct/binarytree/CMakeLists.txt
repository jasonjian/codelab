SET(BINARY_TREE_LIB BinaryTree)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILE )
add_library(${BINARY_TREE_LIB} SHARED ${SOURCE_FILE})

target_link_libraries( ${BINARY_TREE_LIB}
                        ${REPO_DIR}/../build/userdata/libUserData.so)
