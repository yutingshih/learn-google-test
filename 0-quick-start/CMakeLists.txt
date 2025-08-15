cmake_minimum_required(VERSION 3.14)
project(quick-start)

include(../cmake/EnableGTest.cmake)

add_executable(
    hello_test
    hello_test.cc
)
target_link_libraries(
    hello_test
    GTest::gtest_main
)

gtest_discover_tests(hello_test)
