// -------------
// Coverage1.c++
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
    cout << "Coverage1.c++" << endl;

    assert(cycle_length(1) == 1);

    cout << "Done." << endl;
    return 0;}

/*
% g++ -std=c++11 -fprofile-arcs -ftest-coverage -pedantic -Wall -isystem /usr/local/include/gtest -pthread Coverage1.c++ -o Coverage1.app /usr/local/lib/gtest_main.a
Coverage1.app
Coverage1.c++
Done.



% gcov -b Coverage1.c++
File 'Coverage1.c++'
Lines executed:69.23% of 13
Branches executed:80.00% of 10
Taken at least once:40.00% of 10
No calls
Coverage1.c++:creating 'Coverage1.c++.gcov'
...



% cat Coverage1.c++.gcov
...
*/
