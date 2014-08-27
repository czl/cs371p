// ---------------
// Exceptions3.c++
// ---------------

http://www.cplusplus.com/doc/tutorial/exceptions/

#include <cassert>   // assert
#include <cstring>   // strcmp
#include <exception> // exception
#include <iostream>  // cout, endl;

struct My_Exception : std::exception {
    const char* what () const throw () {
        return "My_Exception";}};

int main () {
    using namespace std;
    cout << "Exceptions3.c++" << endl;

    My_Exception x;
    exception&   y = x;
    assert(strcmp(y.what(), "My_Exception") == 0);

    cout << "Done." << endl;
    return 0;}
