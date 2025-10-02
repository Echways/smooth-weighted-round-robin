cmake_minimum_required(VERSION 3.16)
project(cpp_balancer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(swrr
    src/swrr/swrr.cpp
    src/server/server.cpp
)
target_include_directories(swrr PUBLIC ${CMAKE_SOURCE_DIR}/includes)

enable_testing()
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.14.0
)

set(BUILD_GTEST ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

message(STATUS "Attempting to fetch and build googletest with FetchContent...")
FetchContent_MakeAvailable(googletest)

if(NOT TARGET gtest AND NOT TARGET gtest_main)
  find_package(GTest QUIET)
  if(NOT GTest_FOUND)
    message(FATAL_ERROR "GoogleTest not available. Either enable network for FetchContent, add googletest as a submodule, or install googletest on the system.")
  endif()
endif()

add_subdirectory(tests)
