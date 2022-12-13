#!/bin/bash

gcc -o homework3_1single homework3_1single.c -lm
gcc -o homework3_1double homework3_1double.c -lm
gcc -o homework3_2a homework3_2a.c ./NumRec/nrutil.c ./NumRec/gaussj.c -lm

echo ------Number 1 single--------
./homework3_1single
cat phi_table_single.dat

echo ------Number 1 double--------
./homework3_1double
cat phi_table_double.dat

echo ------Number 2a--------
./homework3_2a

echo ------Number 2b--------

python HW_3d_plot.py
echo 3D plot saved to cwd


