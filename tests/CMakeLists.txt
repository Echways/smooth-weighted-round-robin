add_executable(test_swrr
    test_swrr.cpp
)


target_include_directories(test_swrr PRIVATE ${CMAKE_SOURCE_DIR}/includes)
target_link_libraries(test_swrr PRIVATE swrr gtest)

include(GoogleTest)
gtest_discover_tests(test_swrr)