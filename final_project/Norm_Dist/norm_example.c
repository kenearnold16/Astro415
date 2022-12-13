# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "./bmnorm.c"
# include "./ran1.c"


// Example of how to call norm:

int main(void){
    FILE *fp;
    long s1 = 11223344; // seed 1
    long s2 = 55667788; // seed 2
    float U1, U2;

    float mu = 5; // mean
    float var = 1; // variance
    float G; // define variable for norm
    int n, N = 1000000; // number of samples

    fp = fopen("norm_dist.txt", "w");
    for(n = 0; n < N; n++){
        U1 = ran1(&s1);
        U2 = ran1(&s2);
        G = bmnorm(U1, U2, mu, var); // calling the norm function
        fprintf(fp, "\n%f\n", G);
        printf("\n%d %f\n", n, G);
    }
    fclose(fp);
}