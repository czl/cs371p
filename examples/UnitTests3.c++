// --------------
// UnitTests3.c++
// --------------

// https://code.google.com/p/googletest/
// https://code.google.com/p/googletest/wiki/Primer#Assertions

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

struct MyUnitTests : testing::Test
    {};

TEST_F(MyUnitTests, test_1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST_F(MyUnitTests, test_2) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST_F(MyUnitTests, test_3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% g++-4.7 -pedantic -std=c++11 -Wall UnitTests3.c++ -o UnitTests3 -lgtest -lgtest_main -pthread



% UnitTests3
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from MyUnitTests
[ RUN      ] MyUnitTests.test_1
[       OK ] MyUnitTests.test_1 (0 ms)
[ RUN      ] MyUnitTests.test_2
[       OK ] MyUnitTests.test_2 (0 ms)
[ RUN      ] MyUnitTests.test_3
[       OK ] MyUnitTests.test_3 (0 ms)
[----------] 3 tests from MyUnitTests (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 3 tests.
*/
