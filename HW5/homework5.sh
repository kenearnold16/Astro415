#!/bin/bash

#make clean
rm -rf plots
mkdir plots

echo __________This is Number 1________________
python plot_HW5_1.py

echo __________________________________________

echo __________This is Number 2________________
python plot_HW5_2.py

echo __________________________________________

#make clean
rm *.dat

