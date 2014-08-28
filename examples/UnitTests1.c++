// --------------
// UnitTests1.c++
// --------------

// https://code.google.com/p/googletest/
// https://code.google.com/p/googletest/wiki/Primer#Assertions

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

int cycle_length (int n) {
    assert(n > 0);
    int c = 0;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(MyUnitTests, test_1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(MyUnitTests, test_2) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST(MyUnitTests, test_3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% ls -al /usr/include/gtest/
...
-rw-r--r-- 1 root root 82450 Apr 15  2011 /usr/include/gtest/gtest.h
...



% locate libgtest.a
...
/usr/lib/libgtest.a
...



% locate libgtest_main.a
...
/usr/lib/libgtest_main.a
...



% locate libpthread.a
/usr/lib/x86_64-linux-gnu/libpthread.a
/usr/lib32/libpthread.a



% g++-4.7 -pedantic -std=c++11 -Wall UnitTests1.c++ -o UnitTests1 -lgtest -lgtest_main -pthread



% UnitTests1
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from MyUnitTests
[ RUN      ] MyUnitTests.test_1
UnitTests1: UnitTests1.c++:22: int cycle_length(int): Assertion `c > 0' failed.
*/
