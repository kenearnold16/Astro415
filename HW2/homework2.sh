#!/bin/bash

N=(100 200 300 400 500 600 700 800 900 1000 3000 10000 30000 50000)
arr_len=${#N[@]}

gcc -o homework2_1a homework2_1a.c
gcc -o homework2_1b homework2_1b.c
gcc -O2 -o homework2_1c homework2_1b.c
gcc -o homework2_2 homework2_2.c -lm

echo ----------Number 1a------------
echo N = "700"
echo "700" | ./homework2_1a

echo ----------Number 1b------------

for (( n=0; n<arr_len; n++))
do
    variable_name=$(echo "${N[$n]}" | ./homework2_1b)
    echo $variable_name
done
python plot_execution_times.py
rm execution_time.dat

echo ----------Number 1c------------

for (( n=0; n<arr_len; n++))
do
    variable_name=$(echo "${N[$n]}" | ./homework2_1c)
    echo $variable_name
done
python plot_execution_times_optimized.py
rm execution_time.dat

echo ----------Number 2------------
./homework2_2


