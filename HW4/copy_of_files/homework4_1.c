#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

float *P, *P_inv, u;
int N, i, j, length;
long A;
FILE *file;

/* Doing #2 on HW3 */
int main(void){

    N = 1e6;
    P = malloc(N*sizeof(float));
    P_inv = malloc(N*sizeof(float));
    A = 1371289471;

    file = fopen("P_inv.dat", "w");
    for(i=0;i<N;i++){
        u = ran1(&A);
        P_inv[i] = sqrt(-2*log(1-u));

        fprintf(file, "%f\n", P_inv[i]);
    }
    fclose(file);

    return 0;
}



