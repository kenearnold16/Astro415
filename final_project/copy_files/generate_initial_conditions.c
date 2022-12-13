#include <stdio.h>
#include <math.h>
#include <string.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"


float R, W_m1, W_m2, W_v1, W_v2, R1, m, v_mean, v_variance, M, x, y, z, vx, vy, vz;
int n, i, j, k, count;
long A, B, C, D, E, F, G, H, I, J, K, L, P;
FILE *file;

float bmnorm(float u1, float u2, float mean, float var){
    float normal = (sqrtf(-2*var*logf(u1))*cosf(2*M_PI*u2)) + mean;
    return normal;
}

int main(void){

    R = 1000000.0;
    R1 = 1000000.0;
    W_v1 = 0.2;
    W_v2 = 0.2;
    W_m1 = 500.0;
    W_m2 = 100.0;
    scanf("%d",&n);

    A = 4732894723;
    B = 6954068546;
    C = 5743289789;
    D = 4382948950;
    E = 1234398599;
    F = 6859340394;
    G = 1347812978;
    H = 5842904892;
    I = 3217899743;
    J = 9238472483;
    K = 2871932372;
    L = 3819034839;
    P = 7489312847;

    file = fopen("initial_conditions.txt", "w");

    for(j=0;j<n-1;j++){

        v_mean = 0.0;

        x = bmnorm(ran1(&F), ran1(&E), 0.0, R);
        y = bmnorm(ran1(&D), ran1(&C), 0.0, R);
        z = bmnorm(ran1(&B), ran1(&A), 0.0, R);
        if(pow(x,2) + pow(y,2) + pow(z,2) < R1){
          m = W_m1;
          count += 1;
          vx = W_v1*bmnorm(ran1(&G), ran1(&H), v_mean, v_variance);
          vy = W_v1*bmnorm(ran1(&I), ran1(&J), v_mean, v_variance);
          vz = W_v1*bmnorm(ran1(&K), ran1(&L), v_mean, v_variance);
        }
        else if(pow(x,2) + pow(y,2) + pow(z,2) > R1){
          m = W_m2;
          v_variance = (n*m)/(3*R);
          vx = W_v2*bmnorm(ran1(&G), ran1(&H), v_mean, v_variance);
          vy = W_v2*bmnorm(ran1(&I), ran1(&J), v_mean, v_variance);
          vz = W_v2*bmnorm(ran1(&K), ran1(&L), v_mean, v_variance);
        }

        if(pow(x,2) + pow(y,2) + pow(z,2) <= pow(R,2)){
           fprintf(file, "%f %f %f %f %f %f %f\n", m, x, vx, y, vy, z, vz);
        }
        else{
            j=j-1;
        }
    }
    printf("%d", count);
    fprintf(file, "%f %f %f %f %f %f %f\n", W_m1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    fclose(file);
}
