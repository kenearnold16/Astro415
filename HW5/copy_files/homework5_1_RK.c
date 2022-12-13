#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

float *t_arr, *x, step, total_t, step_size;
int i;
FILE *file;

void derivs(float t, float f[], float df_dt[]){

     df_dt[1] = f[2];
     df_dt[2] = -f[1];
}

/* Doing #1 on HW5 RK4 */
int main(void){

    total_t = 15.0;
    scanf("%f", &step);
    step_size = (total_t/step)+1;
    printf("total number of steps: %f\n", step_size);
    printf("step size: %f\n", step);

    t_arr = malloc(step_size*sizeof(float));
    x = malloc(step_size*sizeof(float));

    float *f = vector(1,2);
    float *df_dt = vector(1,2);
    float t;
    int n_sys = 2;

    x[0] = 0;
    f[1] = 0;
    f[2] = 1;
    t_arr[0] = 0;

    for(i=1;i<step_size;i++){
       t_arr[i] = t_arr[i-1] + step;
    }

    file = fopen("RK4.dat", "w");

    for(i=1; i<step_size;i++){
        derivs(t_arr[i], f, df_dt);
        rk4(f, df_dt, n_sys, t, step, f, &derivs);
        x[i] = f[1];
    }

    for(i=0;i<step_size;i++){
       fprintf(file, "%f\t%f\n", x[i], t_arr[i]);

    }

    fclose(file);
    return 0;
}
