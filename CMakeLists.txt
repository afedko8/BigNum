cmake_minimum_required(VERSION 3.14)
project(BigNum CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
endif()

add_library(bignum_lib src/big_num.cpp src/bignum.h)
target_include_directories(bignum_lib PUBLIC src)

add_executable(big_num src/main.cpp)
target_link_libraries(big_num PRIVATE bignum_lib)

find_package(GTest REQUIRED)
add_executable(run_tests tests/test_main.cpp tests/bigint_comparison_test.cpp)
target_link_libraries(run_tests PRIVATE bignum_lib GTest::gtest GTest::gtest_main)

include(CTest)
include(GoogleTest)
gtest_discover_tests(run_tests)