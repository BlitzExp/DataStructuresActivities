#!/bin/bash
truncate -s 0 data.txt

g++ -o Quick.o Quicksort.cpp
./Quick.o

g++ -o NewAlgorithm.o NewAlgorithm.cpp
./NewAlgorithm.o

