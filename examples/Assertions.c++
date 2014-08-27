// --------------
// Assertions.c++
// --------------

// http://www.cplusplus.com/reference/cassert/assert/

#include <cassert>  // assert
#include <iostream> // cout, endl

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

int main () {
    using namespace std;
    cout << "Assertions.c++" << endl;

    assert(cycle_length( 1) == 1);
    assert(cycle_length( 5) == 6);
    assert(cycle_length(10) == 7);

    cout << "Done." << endl;
    return 0;}

/*
% g++-4.7 -pedantic -std=c++11 -Wall Assertions.c++ -o Assertions
% Assertions
Assertions.c++
Assertions: Assertions.c++:17: int cycle_length(int): Assertion `c > 0' failed.



% g++-4.7 -pedantic -std=c++11 -DNDEBUG -Wall Assertions.c++ -o Assertions
% Assertions
Assertions.c++
Done.
*/
