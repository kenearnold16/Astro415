# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "./erfinvx.c"

int main(void){
    FILE* fp;
    int n, N = 100;
    float* x = malloc(N*sizeof(float));
    float erfinv_x;
    int s = 100; // number of sum elements

    fp = fopen("erfinv.txt", "w");
    for(n = 1; n < N; n++){
        x[n] = 2*((float)n/(float)N) - 1; // generate numbers between -1 and 1 with 1000 steps
        erfinv_x = erfinvx(s, x[n]);
        fprintf(fp, "\n%f %f\n", x[n], erfinv_x);
        printf("\n%d %f %f\n", n, x[n], erfinv_x);
    }
    fclose(fp);
}