cmake_minimum_required(VERSION 3.16)
project(cpp_balancer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(swrr
    src/swrr/swrr.cpp
    src/server/server.cpp
)
target_include_directories(swrr PUBLIC ${CMAKE_SOURCE_DIR}/includes)


include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.14.0
)


enable_testing()
add_subdirectory(tests)