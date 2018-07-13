CC=g++
CFLAGS=-c

all: ./main

main: KClustering.o BinaryHeap.o  DisjointSet.o Node.o main.cpp
	@$(CC) -o main KClustering.o BinaryHeap.o DisjointSet.o Node.o main.cpp

KClustering.o: KClustering.hpp KClustering.cpp
	@$(CC) KClustering.hpp KClustering.cpp $(CFLAGS)
	
BinaryHeap.o: binary-heap/BinaryHeap.hpp binary-heap/BinaryHeap.cpp
	@$(CC) binary-heap/BinaryHeap.hpp binary-heap/BinaryHeap.cpp $(CFLAGS)	

DisjointSet.o: disjoint-set/DisjointSet.hpp disjoint-set/DisjointSet.cpp
	@$(CC) disjoint-set/DisjointSet.hpp disjoint-set/DisjointSet.cpp $(CFLAGS)

Node.o: disjoint-set/Node.hpp disjoint-set/Node.cpp
	@$(CC) disjoint-set/Node.hpp disjoint-set/Node.cpp $(CFLAGS)
	
run:
	@./main
