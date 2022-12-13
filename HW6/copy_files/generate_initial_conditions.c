#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

float R, W_r, W_v, W_m, m, x, y, z, vx, vy, vz;
int n, i, j;
long A, B, C, D, E, F, G;
FILE *file;

/* Doing #2 on HW3 */
int main(void){

    W_r = 100.0;
    R = pow(W_r,2);
    W_v = 0.01;
    W_m = 1.5;
    scanf("%d",&n);
    float hw = 1;
    float M_b = 10.0;
    float X_b = 0.0;
    float Y_b = 0.0;
    float Z_b = 0.0;
    float V_xb = 0.0;
    float V_yb = 0.0;
    float V_zb = 0.0;

    A = 4732894723;
    B = 6954068546;
    C = 5743289789;
    D = 4382948950;
    E = 1234398599;
    F = 6859340394;
    G = 1347812978;

    file = fopen("initial_conditions.txt", "w");

    if(hw == 1){
        fprintf(file, "%f %f %f %f %f %f %f\n", M_b, X_b, Y_b, Z_b, V_xb, V_yb, V_zb);
        for(j=0;j<n-1;j++){

           x = W_r*(ran1(&A) - 0.5);
           y = W_r*(ran1(&B) - 0.5);
           z = 1*(ran1(&C) - 0.5);
           vx = W_v*(ran1(&D) - 0.5);
           vy = W_v*(ran1(&E) - 0.5);
           vz = W_v*(ran1(&F) - 0.5);
           m = W_m*ran1(&G);

           if(m > 0 && pow(x,2) + pow(y,2) + pow(z,2) <= R && pow(x,2) + pow(y,2) + pow(z,2) >= -R){
             fprintf(file, "%f %f %f %f %f %f %f\n", m, x, vx, y, vy, z, vz);
           }
           else{
               j=j-1;
           }
        }
    }

    else if(hw == 0){

         fprintf(file, "%f %f %f %f %f %f %f\n", 1.0, -0.5, 0.0, 0.0, -0.5, 0.0, 0.0);
         printf("%f %f %f %f %f %f %f\n", 1.0, -0.5, 0.0, 0.0, -0.5, 0.0, 0.0);
         fprintf(file, "%f %f %f %f %f %f %f\n", 1.0, 0.5, 0.0, 0.0, 0.5, 0.0, 0.0);
         printf("%f %f %f %f %f %f %f\n", 1.0, 0.5, 0.0, 0.0, 0.5, 0.0, 0.0);
    }
    fclose(file);
    return 0;
}



