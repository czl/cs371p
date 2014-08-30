// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <utility>  // pair

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param r an std::istream
 * @return a pair of ints, representing the beginning and end of a range, (b, e]
 */
std::pair<int, int> collatz_read (std::istream& r);

// ------------
// collatz_eval
// ------------

/**
 * @param p a pair of ints, representing the beginning and end of a range, (b, e]
 * @return the max cycle length of the range
 */
int collatz_eval (const std::pair<int, int>& p);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an std::ostream
 * @param p a pair of ints, representing the beginning and end of a range, (b, e]
 * @param v the max cycle length
 */
void collatz_print (std::ostream&, const std::pair<int, int>&, int);

// -------------
// collatz_solve
// -------------

/**
 * @param r an std::istream
 * @param w an std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);

#endif // Collatz_h
