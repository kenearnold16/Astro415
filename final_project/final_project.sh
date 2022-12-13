#!/bin/bash

gcc -o GIC generate_initial_conditions.c ./NumRec/ran1.c ./NumRec/nrutil.c -lm
gcc -o final_project final_project.c rk4.c lf2.c ./NumRec/nrutil.c -lm
n=1000
speed=1
limit=20
file=(lf.txt rk4.txt)
$(echo "${n}" | ./GIC)
cat initial_conditions.txt

$(echo "${n}" | ./final_project lf.txt)

cp lf.txt plot_orbit
cd ./plot_orbit
#python 3D_Nbody_plot.py ${n} ${speed} ${limit}
python contour.py ${n} ${speed} ${limit}
rm *.txt

