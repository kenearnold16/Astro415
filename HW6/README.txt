Homework 6 
Kenneth Arnold 

TO RUN CODE: 

sh homework6.sh 

This code does each plot of Phase and Energy for each eccentricity.
This shell script only does number 1 on the homework and it takes about 30 seconds to run 

NOTE: If there are a bunch of nan values in the print statement 
it is because the initial_conditions.txt file is setup for the bonus question
To reset the initial conditions for number one simply change the variable hw in the file 
generate_initial_conditions.c to 0 and the code will work.

homework6.sh will generate gifs of the orbits in number one as well.

TO RUN BONUS QUESTION: 

sh bonus.sh

NOTE: bonus.sh TAKES A VERY LONG TIME TO RUN 
I would not recommend running this code
if you do decide to run this code the variable hw in generate_initial_conditions.c 
needs to be set to 1. 

bonus.sh makes a 3D gif of an Nbody code for 200 particles
you can also shorten the time to run by changing the variable n in bonus.sh to a smaller 
amount of particles and it won't take as long. 

I include all gifs in the ELMS submission.

