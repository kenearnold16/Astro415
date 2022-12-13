#!/bin/bash

gcc -o homework4_1 homework4_1.c ./NumRec/ran1.c -lm
gcc -o homework4_2 homework4_2.c ./NumRec/ran1.c -lm

echo ----------Number 1-------------
./homework4_1

echo finished Rayleigh DD

echo ----------Number 2-------------
./homework4_2
cat Mass.dat

python homework4_plots.py

