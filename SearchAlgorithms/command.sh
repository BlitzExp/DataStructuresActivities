#!/bin/bash
truncate -s 0 data.txt
g++ -o search.o Searchs.cpp
for i in 1 2 3 4 5
do
    ./search.o
    sleep 1
done
