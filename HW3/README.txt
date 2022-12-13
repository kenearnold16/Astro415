Homework 3 code

To run the code: 

sh homework3.sh

This will compile and run each part on the homework succesively 
________________________________________________________________________________
First, it will run number 1 for single precision and print the resulting table.
The first column is n, the second column is (phi^n-1 - phi^n), the third column
is (phi*phi^n-1).

Next it will run number 1 for double precision and print the resulting table.

________________________________________________________________________________
Next it will run the code to determine the instantaneous spin period of the data
from the file ps2.dat.

-First the code imports the data from ps2.dat and then seperates the elements of
the r and v column vectors into their own arrays. 

-Next the code takes this data and calculates each L by a cross product and sums
each element.

-Next the code calculates the Intertia tensor by subtraction and sums each of
its elements.

-Next the code takes the Inertia tensor and the L column vector and inputs them
into the gaussj function from NumRec and this produces omega which we then used
to get the instantaneous spin period by P = (2*pi)/omega. The code then prints
the results (NOTE: The code also prints the inertia tensor, the L column
vector, and the first line of data from ps2.dat).
________________________________________________________________________________

Finally the sh script will run the python code I used to plot the data from
ps2.dat. This produces a 3D plot of the body and plots a color bar with the
magnitude of the tangent velocity at that point. The .png is saved to the cwd
and is also put in the homeworks pdf.



