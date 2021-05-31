CC = g++
CFlag = -Wall -Werror -g

.PHONY: everything
everything: avl

avl: anagram.o avl.o
anagram.o: anagram.cpp
avl.o: avl.hpp avl.cpp

.PHONY: clean
clean:
	rm -vf *.o avl