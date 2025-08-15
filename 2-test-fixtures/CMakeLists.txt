cmake_minimum_required(VERSION 3.14)
project(test-fixtures)

include(../cmake/EnableGTest.cmake)

add_executable(
    test_queue
    test_queue.cc
)
target_link_libraries(
    test_queue
    GTest::gtest_main
)

gtest_discover_tests(test_queue)
