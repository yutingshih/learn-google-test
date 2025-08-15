cmake_minimum_required(VERSION 3.14)
project(simple-tests)

include(../cmake/EnableGTest.cmake)

add_executable(
    test_factorial
    test_factorial.cc
    factorial.cc
)
target_link_libraries(
    test_factorial
    GTest::gtest_main
)

gtest_discover_tests(test_factorial)
