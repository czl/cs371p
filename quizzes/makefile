cs:

OS := $(shell uname)

ifeq ($(OS), Darwin)
	BOOST    := -I/usr/local/include/boost
	CCX      := g++     -pedantic -std=c++11 $(BOOST) -Wall
	CCY      := clang++ -pedantic -std=c++11 $(BOOST) -Wall -Wno-sizeof-array-argument
	GTEST    := -lgtest_main
    VALGRIND :=
else
	BOOST    := -I/public/linux/include/boost-1_38
	CCX      := g++     -pedantic -std=c++0x $(BOOST) -Wall
	CCY      := clang++ -pedantic -std=c++11 $(BOOST) -Wall -Wno-sizeof-array-argument
	GTEST    := -lgtest -lpthread -lgtest_main
    VALGRIND := $(shell which valgrind)
endif

CC = $(CCX)

.PRECIOUS: %.app
.PRECIOUS: %.class

%.app: %.c++
	$(CC) $< -o $@

%.c++x: %.app
	$(VALGRIND) $<

%.javax: %.class
	java -ea $(patsubst %.class,%,$<)

clean:
	rm -f *.app
	rm -f *.class
