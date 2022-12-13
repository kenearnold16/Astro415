#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

double phi;
int n, m, i, j, k, l, n_length, *N;
double *phi_column1, *phi_column2;
FILE *file;

/* Doing #1 on HW3 */
int main(void){

    n_length = 20;
    phi_column1 = malloc(n_length*sizeof(double));
    phi_column2 = malloc(n_length*sizeof(double));
    N = malloc(n_length*sizeof(double));

    phi = (sqrt(5) - 1)/2;
    for(i = 0; i < n_length; i++){
       N[i] = i + 1;
    }
    for(i = 0; i < n_length; i++){
       n = i + 1;
       phi_column1[i] = (pow(phi, n-1) - pow(phi,n));
    }
    for(i = 0; i < n_length; i++){
       n = i + 1;
       phi_column2[i] = phi*pow(phi,n-1);
    }
    file = fopen("phi_table_double.dat", "w");
    fprintf(file,"n\t(phi^n-1 - phi^n)\t(phi*phi^n-1)\n");
    for(i = 0; i < n_length; i++){
       fprintf(file, "%d\t%f\t%f\n", N[i], phi_column1[i], phi_column2[i]);
    }
    fclose(file);
    return 0;
}



