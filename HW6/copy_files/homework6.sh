#!/bin/bash

gcc homework6.c rk4.c lf2.c eul1.c ./NumRec/nrutil.c -lm
gcc -o GIC generate_initial_conditions.c ./NumRec/ran1.c -lm
n=2

variable_name=$(echo "${n}" | ./GIC ${n})
ecc=(0.5 0.9)
h=(0.05 0.003)
speed=(10 100)
names=(lf rk4)
file=(lf.txt rk4.txt)
ecc_len=${#ecc[@]}
names_len=${#names[@]}

for (( n=0; n<ecc_len; n++))
do
    for((l=0;l<names_len;l++))
    do

       variable_name=$(echo "${ecc[$n]}" "${h[$n]}" | ./a.out ${file[$l]})
       echo $variable_name
       mv ${file[$l]} ${ecc[$n]}${file[$l]}
       echo ${ecc[$n]}${file[$l]}
       #cat ${ecc[$n]}${file[$l]}
       mv ${ecc[$n]}${file[$l]} ./plot_orbit

       cd ./plot_orbit
       python plot_orbit.py ${names[$l]} ${ecc[$n]} ${speed[$n]}
       cd ..
    done

done
