#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

float *t_arr, *v_x, *v_y, *x, *y, step, step_size;
int total_t, i;
FILE *file;

void derivs(float t, float f[], float df_dt[]){

     df_dt[1] = f[2];
     df_dt[2] = -(2*f[1])/(pow((1+2*f[1]*f[1]+2*f[3]*f[3]), 1.5));
     df_dt[3] = f[4];
     df_dt[4] = -(2*f[3])/(pow((1+2*f[1]*f[1]+2*f[3]*f[3]), 1.5));
}

/* Doing #2 on HW5 RK4 */
int main(void){

    total_t = 100.0;
    scanf("%f", &step);
    step_size = (total_t/step)+1;
    printf("total number of steps: %f\n", step_size);
    printf("step size: %f\n", step);

    t_arr = malloc(step_size*sizeof(float));
    x = malloc(step_size*sizeof(float));
    y = malloc(step_size*sizeof(float));
    v_x = malloc(step_size*sizeof(float));
    v_y = malloc(step_size*sizeof(float));

    float *f = vector(1,4);
    float *df_dt = vector(1,4);
    float t;
    int n_sys = 4;

    x[0] = 1;
    y[0] = 0;
    v_x[0] = 0;
    v_y[0] = 0.1;

    f[1] = 1;
    f[2] = 0;
    f[3] = 0;
    f[4] = 0.1;

    t_arr[0] = 0;

    for(i=1;i<step_size;i++){
       t_arr[i] = t_arr[i-1] + step;
    }

    file = fopen("RK4.dat", "w");

    for(i=1; i<step_size;i++){
        derivs(t_arr[i], f, df_dt);
        rk4(f, df_dt, n_sys, t, step, f, &derivs);
        x[i] = f[1];
        y[i] = f[3];
        v_x[i] = f[2];
        v_y[i] = f[4];

    }

    for(i=0;i<step_size;i++){
       fprintf(file, "%f\t%f\t%f\t%f\t%f\n", x[i], y[i], v_x[i], v_y[i], t_arr[i]);

    }

    fclose(file);
    return 0;
}
