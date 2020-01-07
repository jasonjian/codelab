cmake_minimum_required(VERSION 3.10)
project(CodeLab VERSION 1.0)

option(USE_CODELAB_ALGORITHM "use jason's own algorithm library")

configure_file(CodeLabConfig.h.in CodeLabConfig.h)

set (CMAKE_CXX_STANDARD 11)

set("REPO_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
set("ALGORITHM_DIR" ${REPO_DIR}/algorithm)
set("DATASTRUCT_DIR" ${REPO_DIR}/datastruct)
set("USERDATA_DIR" ${REPO_DIR}/userdata)
set("UTILS_DIR" ${REPO_DIR}/utils)

include_directories(${REPO_DIR})
include_directories(${ALGORITHM_DIR})
include_directories(${DATASTRUCT_DIR})
include_directories(${USERDATA_DIR})
include_directories(${UTILS_DIR})

add_subdirectory(algorithm)
add_subdirectory(userdata)
add_subdirectory(datastruct)
add_subdirectory(utils)

add_executable(codelab main.cpp)

target_link_libraries(codelab PUBLIC
  ${REPO_DIR}/../build/datastruct/binarytree/libBinaryTree.so
  )

target_include_directories(codelab PUBLIC
  "${PROJECT_BINARY_DIR}"
  )
