cmake_minimum_required(VERSION 3.0)
include(FetchContent)

project(ReedSolomon)

set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

#find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)
enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

#include_directories(src)
add_subdirectory(GF2)
add_subdirectory(main)
#add_subdirectory(test)
#add_subdirectory(lib/googletest)
