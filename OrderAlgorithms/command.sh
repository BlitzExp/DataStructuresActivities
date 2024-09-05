#!/bin/bash
truncate -s 0 data.txt

g++ -o Bubble.o Bubblesort.cpp
./Bubble.o



g++ -o Selection.o Selectionsort.cpp
./Selection.o



g++ -o Insertion.o Insertionsort.cpp
./Insertion.o



g++ -o Merge.o Mergesort.cpp
./Merge.o



g++ -o Quick.o Quicksort.cpp
./Quick.o



g++ -o Exchange.o Exchangesort.cpp
./Exchange.o



g++ -o Comb.o Combsort.cpp
./Comb.o



g++ -o Sort.o Sort.cpp
./Sort.o

