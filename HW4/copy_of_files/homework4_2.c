#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

float sigma, V, M, *n, rho, rho_squared, x, y, z, f, f_squared, p;
int N, i, j, length;
long A, B, C;
FILE *file;

/* Doing #2 on HW3 */
int main(void){

    V = 6;
    length = 7;
    n = malloc(length*sizeof(float));

    for(j=0;j<length;j++){
       n[j] = pow(10,j+1);
    }

    A = 420;
    B = 69;
    C = 666;

    file = fopen("Mass.dat", "w");
    fprintf(file,"N\tM\t+-sigma\n");
    for(j=0;j<length;j++){

       N = n[j];

       rho = 0;
       rho_squared = 0;

       for(i=0; i<N;i++){

          x = V*ran1(&A) - 3;
          y = V*ran1(&B) - 3;
          z = V*ran1(&C) - 3;

          if(x >= 0 && y>= -1 && pow(x,2) + pow(y,2) + pow(z,2) <= 9){
             rho += 1 + pow(x,2) + 3*pow((z+y), 2);
             rho_squared += pow((1 + pow(x,2) + 3*pow((z+y), 2)), 2);
          }

          /*printf("%f\n", pow(x,2) + pow(y,2) + pow(z,2));*/


       }
       p = (4*p)/N;

       f = rho/N;
       f_squared = rho_squared/N;
       sigma = sqrt(((f_squared) - (pow(f,2)))/N);

       M = V*V*V*f;
       fprintf(file, "%d\t%f\t%f\n", N,M, sigma);
    }

    fclose(file);
    return 0;
}



