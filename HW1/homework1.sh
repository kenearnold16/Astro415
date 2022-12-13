#!/bin/bash

arr=(1000000 3000000 10000000 30000000 100000000 300000000 1000000000)
arr_len=${#arr[@]}
rm output.txt
gcc homework1a.c -lm
echo integer add_5 minus_5 times_1 div_1 sqrt_1 pow_05 >> output.txt
for ((n=0; n<arr_len; n++))
do
    variable_name=$(echo "${arr[$n]}" | ./a.out)
    echo $variable_name >> output.txt
done
cat output.txt
python homework1_plot.py
