#!/bin/bash

gcc -o GIC generate_initial_conditions.c ./NumRec/ran1.c -lm
gcc -o bonus bonus.c eul1.c rk4.c lf2.c ./NumRec/nrutil.c -lm
n=50
speed=10
file=(lf.txt rk4.txt)
$(echo "${n}" | ./GIC)
cat initial_conditions.txt

$(echo "${n}" | ./bonus lf.txt)
cat lf.txt

mv lf.txt plot_orbit
cd ./plot_orbit
python 3D_Nbody_plot.py ${n} ${speed}

