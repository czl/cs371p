all:

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunCollatz
	rm -f RunCollatz.out
	rm -f RunCollatz.tmp
	rm -f RunCollatz.valgrind.out
	rm -f TestCollatz
	rm -f TestCollatz.out
	rm -f TestCollatz.valgrind.out

scrub:
	make --no-print-directory clean
	rm -f Collatz.log
	rm -f Doxyfile
	rm -rf html
	rm -rf latex

Collatz.log:
	git log > Collatz.log

Doxyfile:
	doxygen -g

html: Collatz.h Collatz.c++ RunCollatz.c++ TestCollatz.c++
	doxygen Doxyfile

RunCollatz: Collatz.h Collatz.c++ RunCollatz.c++
	g++-4.7 -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz

RunCollatz.out: RunCollatz RunCollatz.in
	RunCollatz < RunCollatz.in > RunCollatz.out

RunCollatz.tmp: RunCollatz RunCollatz.in RunCollatz.out
	RunCollatz < RunCollatz.in > RunCollatz.tmp
	diff RunCollatz.out RunCollatz.tmp

RunCollatz.valgrind.out: RunCollatz RunCollatz.in
	valgrind RunCollatz < RunCollatz.in > RunCollatz.valgrind.out 2>&1

TestCollatz: Collatz.h Collatz.c++ TestCollatz.c++
	g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread

TestCollatz.out: TestCollatz
	TestCollatz                 >  TestCollatz.out
	gcov-4.7 -b Collatz.c++     >> TestCollatz.out
	gcov-4.7 -b TestCollatz.c++ >> TestCollatz.out

TestCollatz.valgrind.out: TestCollatz
	valgrind TestCollatz        >  TestCollatz.valgrind.out 2>&1
	gcov-4.7 -b Collatz.c++     >> TestCollatz.valgrind.out
	gcov-4.7 -b TestCollatz.c++ >> TestCollatz.valgrind.out
