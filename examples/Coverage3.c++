// -------------
// Coverage3.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

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

int main () {
    using namespace std;
    cout << "Coverage3.c++" << endl;

    assert(cycle_length(1) == 1);
    assert(cycle_length(2) == 2);
    assert(cycle_length(3) == 8);

    cout << "Done." << endl;
    return 0;}

/*
% g++ -std=c++11 -fprofile-arcs -ftest-coverage -pedantic -Wall -isystem /usr/local/include/gtest -pthread Coverage3.c++ -o Coverage3.app /usr/local/lib/gtest_main.a
Coverage3.app
Coverage3.c++
Done.



% gcov -b Coverage3.c++
File 'Coverage3.c++'
Lines executed:100.00% of 15
Branches executed:100.00% of 14
Taken at least once:64.29% of 14
No calls
Coverage3.c++:creating 'Coverage3.c++.gcov'
...



% cat Coverage3.c++.gcov
...
*/
