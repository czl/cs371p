// ---------------
// Exceptions2.c++
// ---------------

// http://www.cplusplus.com/doc/tutorial/exceptions/
// http://www.cplusplus.com/reference/memory/auto_ptr/

#include <cassert>   // assert
#include <cstring>   // strcmp
#include <iostream>  // cout, endl
#include <memory>    // auto_ptr
#include <stdexcept> // domain_error

int f (bool b) {
    if (b)
        throw std::domain_error("abc");
    return 0;}

int main () {
    using namespace std;
    cout << "Exceptions2.c++" << endl;

    try {
        int* const a = new int[10];
        assert(f(false) == 0);
        delete [] a;
        }
    catch (domain_error& e) {
        assert(false);}

    try {
        int* const a = new int[10];
        assert(f(true) == 1);
        assert(false);
        delete [] a;                           // memory leak
        }
    catch (domain_error& e) {
        assert(strcmp(e.what(), "abc") == 0);}

    try {
        const auto_ptr<int> p(new int[10]);
        assert(f(true) == 1);
        assert(false);
        }
    catch (domain_error& e) {
        assert(strcmp(e.what(), "abc") == 0);}

    cout << "Done." << endl;
    return 0;}
