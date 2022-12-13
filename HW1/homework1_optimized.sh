#!/bin/bash

#creates array to run
arr=(1000000 3000000 10000000 30000000 100000000 300000000 1000000000)
#this is the length of the array
arr_len=${#arr[@]}

#ignore this part
rm output.txt
gcc -O2 homework1a.c -lm

echo integer add_5 minus_5 times_1 div_1 sqrt_1 pow_05 >> output.txt

#for loop to change fscanf argument
for (( n=0; n<arr_len; n++))
do
    #takes array value and puts it in the fscanf for you
    #this | means take echo print statement and put it in the command ./a.out
    variable_name=$(echo "${arr[$n]}" | ./a.out)
    echo $variable_name >> output.txt
done

cat output.txt
python homework1_plot_optimized.py
