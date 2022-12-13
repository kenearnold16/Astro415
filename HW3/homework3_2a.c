#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

int N, n, m, i, j, k, l;
float omega, P, *x, *y, *z, *v_x, *v_y, *v_z, *L_x, *L_y, *L_z;
FILE *ps2;

/* Doing #2 on HW3 */

int main(void){

    /* allocating memory */
    float **L = matrix(1, 3, 1, 1);
    float **r = matrix(1, 3, 1, 1);
    float **I = matrix(1, 3, 1, 3);
    float **rr = matrix(1, 3, 1, 3);
    N = 1908;

    x = malloc(N*sizeof(float));
    y = malloc(N*sizeof(float));
    z = malloc(N*sizeof(float));

    L_x = malloc(N*sizeof(float));
    L_y = malloc(N*sizeof(float));
    L_z = malloc(N*sizeof(float));

    v_x = malloc(N*sizeof(float));
    v_y = malloc(N*sizeof(float));
    v_z = malloc(N*sizeof(float));

    /* importing data from ps2.dat */
    ps2 = fopen("ps2.dat", "r");
    for(i = 0; i < N; i++){
        fscanf(ps2,"%f %f %f %f %f %f", &x[i],&y[i],&z[i],&v_x[i],&v_y[i],&v_z[i]);
    }
    fclose(ps2);

    printf("\nfirst line of data file\n");

    printf("%f\t%f\t%f\t%f\t%f\t%f\n", x[0],y[0],z[0],v_x[0],v_y[0],v_z[0]);

    /*doing the cross product rxv*/
    for(i = 0; i<N; i++){
        L_x[i] = (y[i]*v_z[i] - z[i]*v_y[i]);
        L_y[i] = -(x[i]*v_z[i]- z[i]*v_x[i]);
        L_z[i] = (x[i]*v_y[i] - y[i]*v_x[i]);
    }

    /* creating the inertia tensor and summing all the elements */
    for(i = 0; i < N; i++){
        r[1][1] = x[i];
        r[2][1] = y[i];
        r[3][1] = z[i];

        L[1][1] += L_x[i];
        L[2][1] += L_y[i];
        L[3][1] += L_z[i];

        for(m = 1; m < 4; m++){
            for(n = 1; n < 4; n++){
                rr[m][n] = r[m][1]*r[n][1];
            }
        }

        for(j = 1; j < 4; j++){
            for(k = 1; k < 4; k++){
                if(j == k){
                  I[j][k] += (pow(r[1][1],2) + pow(r[2][1],2) + pow(r[3][1],2)) - rr[j][k];
                }
                else{
                  I[j][k] += -rr[j][k];
                }
            }
        }
    }

    printf("\nL vector: \n");
    for(j = 1;j<4;j++){
       printf("%f\n", L[j][1]);
    }
    printf("\nInertia Tensor is: \n");
    for(j = 1;j<4;j++){
       printf("\n");
       for(k = 1;k<4;k++){
          printf("%f\t", I[j][k]);
       }
    }

    /* using gauss jordan function */

    gaussj(I,3,L,1);

    printf("\nomega: \n %f \n %f \n %f\n",L[1][1],L[2][1],L[3][1]);

    omega = sqrt(pow(L[1][1],2) + pow(L[2][1],2) + pow(L[3][1],2));
    printf("\n|omega| = %f\n", omega);

    P = (2*3.1415)/omega;
    printf("\nPeriod (hrs) = %f\n", P/(60*60));

    return 0;
}





