Homework number 1 
Kenneth Arnold

There are various .c files in this folder. The first homework1_int.c was to test the run time of
calculations for integer variables. The second homework1_double.c was to test the run times of
calculations for double-precision type variables.

To run homework1_int.c:

gcc homework1_int.c
./a.out

To run homework1_double.c:

gcc homework1_double.c -lm
./a.out

Next are the shell scripts that enter various n number of iterations for these calcualtions.

The first homework1.sh. This file already contains the compiling within it and a for loop to run the
various n. The output of each iteration in the for loop is then captured and appended to the text file
output.txt. A table of the run times will be printed to the terminal. This shell script also makes a log 
plot of the time vs n using python and saves the .png to the current folder. 

To run the shell script: 

sh homework1.sh 

NOTE: The first time you run this code it may say "cannot rm output.txt" this is because it hasn't been
created yet. This is just so that when the code appends to output.txt it doesn't continuously append
everytime you run the code. Simply ignore this message.

The second shell script is homework1_optimized.sh. This file is exactly the same as homework1.sh except
it contains the optimize flag -O2 to optimize the calculations. This shell script also plots the time vs
n of the calculations in python and saves the .png to the current folder. 

To run the shell script: 

sh homework1_optimized.sh

NOTE: If you want to run this code with the icc compiler instead of gcc you'll have to vim into homework1.sh and change the compiler command by hand.


