#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

double *t, *v, *x, step, step_size;
int total_t, i;
FILE *file;

/* Doing #1 on HW5 Euler Method */
int main(void){

    total_t = 15.0;
    scanf("%le", &step);
    step_size = (total_t/step) + 1;
    printf("total number of steps: %le\n", step_size);
    printf("step size: %le\n", step);

    t = malloc(step_size*sizeof(double));
    x = malloc(step_size*sizeof(double));
    v = malloc(step_size*sizeof(double));

    t[0] = 0.0;
    x[0] = 0.0;
    v[0] = 1.0;

    for(i=1;i<=step_size;i++){
       t[i] = t[i-1] + step;
    }

    file = fopen("Euler_Method.dat", "w");

    for(i=1; i<step_size;i++){
       v[i] = v[i-1] + step*(-x[i-1]);
       x[i] = x[i-1] + step*(v[i-1]);
    }

    for(i=0;i<step_size;i++){
       fprintf(file, "%le\t%le\n", x[i], t[i]);

    }

    fclose(file);
    return 0;
}
