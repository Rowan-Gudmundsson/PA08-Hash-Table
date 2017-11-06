CPP_FLAGS = -Wall -O2 -std=c++98

all: BSTree HashTable test10
	g++ -o test10 BSTree.o HashTable.o test10.o

BSTree: BSTree.cpp BSTree.h
	g++ $(CPP_FLAGS) -c BSTree.cpp

HashTable: HashTable.cpp HashTable.h
	g++ $(CPP_FLAGS) -c HashTable.cpp

test10: test10.cpp
	g++ $(CPP_FLAGS) -c test10.cpp
