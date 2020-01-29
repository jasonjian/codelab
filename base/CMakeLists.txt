#configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
#execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#  RESULT_VARIABLE result
#  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
#if(result)
#  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
#endif()
#execute_process(COMMAND ${CMAKE_COMMAND} --build .
#  RESULT_VARIABLE result
#  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
#if(result)
#  message(FATAL_ERROR "Build step for googletest failed: ${result}")
#endif()
#
## Prevent overriding the parent project's compiler/linker
## settings on Windows
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#
## Add googletest directly to our build. This defines
## the gtest and gtest_main targets.
#add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
#                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
#                 EXCLUDE_FROM_ALL)
#
## The gtest/gtest_main targets carry header search path
## dependencies automatically when using CMake 2.8.11 or
## later. Otherwise we have to add them here ourselves.
#if (CMAKE_VERSION VERSION_LESS 2.8.11)
#  include_directories("${gtest_SOURCE_DIR}/include")
#endif()
#
## Now simply link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
#target_link_libraries(example gtest_main)
#add_test(NAME example_test COMMAND example)


cmake_minimum_required(VERSION 3.10)
project(CodeLab VERSION 1.0)

option(USE_CODELAB_ALGORITHM "use jason's own algorithm library")

configure_file(CodeLabConfig.h.in CodeLabConfig.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
#set(CMAKE_C_COMPILER "/usr/bin/clang")
#set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  message("We use apple clang as our c++ compiler")
endif()


set("REPO_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
set("ALGORITHM_DIR" ${REPO_DIR}/algorithm)
set("DATASTRUCT_DIR" ${REPO_DIR}/datastruct)
set("USERDATA_DIR" ${REPO_DIR}/userdata)
set("UTILS_DIR" ${REPO_DIR}/utils)
set("CPPLAB_DIR" ${REPO_DIR}/cpplab)
set("GTEST_DIR" ${REPO_DIR}/googletest/googletest/include)

set(CMAKE_INSTALL_PREFIX ${REPO_DIR}/../install)

include_directories(${REPO_DIR})
include_directories(${ALGORITHM_DIR})
include_directories(${USERDATA_DIR})
include_directories(${UTILS_DIR})
include_directories(${GTEST_DIR})

add_subdirectory(algorithm)
add_subdirectory(userdata)
add_subdirectory(datastruct)
add_subdirectory(utils)
add_subdirectory(cpplab)
add_subdirectory(googletest)
add_subdirectory(scripts)

add_executable(codelab main.cpp)

find_library(BINARY_TREE_LIB BinaryTree )

target_link_libraries(codelab PUBLIC
  BinaryTree
  SmartPtr
  Shape
  TypeLab
  Callable
  TextPlayer
  Practice
  Greedy
  gtest
  )

target_include_directories(codelab PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${DATASTRUCT_DIR}"
  )
