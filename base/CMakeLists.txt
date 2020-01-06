cmake_minimum_required(VERSION 3.10)

# set the project name
project(JasonLab VERSION 1.0)

option(USE_JASONLAB_ALGORITHM "use jason's own algorithm library")

configure_file(JasonLabConfig.h.in JasonLabConfig.h)

set("REPO_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
set("ALGORITHM_DIR" ${REPO_DIR}/algorithm)
set("DATASTRUCT_DIR" ${REPO_DIR}/datastruct)
set("USERDATA_DIR" ${REPO_DIR}/userdata)
set("UTILS_DIR" ${REPO_DIR}/utils)

set (CMAKE_CXX_STANDARD 11)

option(USE_JASONLAB_ALGORITHM "use jason's own algorithm library")
configure_file(JasonLabConfig.h.in JasonLabConfig.h)

include_directories(${REPO_DIR})
include_directories(${ALGORITHM_DIR})
include_directories(${DATASTRUCT_DIR})
include_directories(${USERDATA_DIR})
include_directories(${UTILS_DIR})

add_subdirectory(algorithm)
add_subdirectory(userdata)
add_subdirectory(datastruct)
add_subdirectory(utils)

#add the executable
add_executable(codelab main.cpp)

#message("${PROJECT_BINARY_DIR}")

#target_include_directories(swordman PUBLIC
#  "${PROJECT_BINARY_DIR}"
#  "${PROJECT_SOURCE_DIR}"
#  )

target_link_libraries(codelab PUBLIC ${BINARY_TREE_LIB})

target_include_directories(codelab PUBLIC
  "${PROJECT_BINARY_DIR}"
  )


