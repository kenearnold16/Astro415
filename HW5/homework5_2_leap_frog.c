#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

float *t, *v_x, *v_y, v_leap_x, v_leap_y, *x, *y, step, step_size;
int total_t, i;
FILE *file;

/* Doing #2 on HW5 Leap Frog*/
int main(void){

    total_t = 100.0;
    scanf("%f", &step);
    step_size = (total_t/step)+1;
    printf("total number of steps: %f\n", step_size);
    printf("step size: %f\n", step);

    t = malloc(step_size*sizeof(float));
    x = malloc(step_size*sizeof(float));
    y = malloc(step_size*sizeof(float));
    v_x = malloc(step_size*sizeof(float));
    v_y = malloc(step_size*sizeof(float));

    t[0] = 0.0;
    x[0] = 1.0;
    y[0] = 0.0;
    v_x[0] = 0.0;
    v_y[0] = 0.1;

    for(i=1;i<=step_size;i++){
       t[i] = t[i-1] + step;
    }

    file = fopen("Leap_Frog.dat", "w");

    for(i=1; i<step_size;i++){

       v_leap_x = v_x[i-1] + (step/2)*(-(2*x[i-1])/(powf((1 + 2*x[i-1]*x[i-1] + 2*y[i-1]*y[i-1]), 1.5)));
       v_leap_y = v_y[i-1] + (step/2)*(-(2*y[i-1])/(powf((1 + 2*x[i-1]*x[i-1] + 2*y[i-1]*y[i-1]), 1.5)));

       x[i] = x[i-1] + (step)*(v_leap_x);
       y[i] = y[i-1] + (step)*(v_leap_y);

       v_x[i] = v_leap_x + (step/2)*(-(2*x[i])/(powf((1 + 2*x[i]*x[i] + 2*y[i]*y[i]), 1.5)));
       v_y[i] = v_leap_y + (step/2)*(-(2*y[i])/(powf((1 + 2*x[i]*x[i] + 2*y[i]*y[i]), 1.5)));

    }

    for(i=0;i<step_size;i++){
       fprintf(file, "%f\t%f\t%f\t%f\t%f\n", x[i], y[i], v_x[i], v_y[i], t[i]);
    }

    fclose(file);
    return 0;
}
