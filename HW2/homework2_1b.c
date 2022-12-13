#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

double t0, t1, dt_A, dt_B, k;
double **array1, **array2;
int i, j, l, N;
FILE *file;

double getCPU(void)
{
     return (double) clock()/CLOCKS_PER_SEC;  /* convert to seconds */
}
/* Doing #1 on HW2 */
int main(void){

        printf("\nEnter the size of your array NxN: ");
        scanf("%d", &N);
        printf("%d\n", N);

        k = 0.0;

        t0 = getCPU();
        /*appending matrix by row */
        array1 = malloc(N*sizeof(double));
        for(l=0; l<N; l++){
           array1[l] = malloc(N*sizeof(double));
        }

        for(i = 0; i < N; i++){
           for(j = 0; j < N; j++){
              k = k+1;
              array1[i][j] = k;
           }
        }
        /* printing matrix
        for(i = 0; i < N; i++){
           for(j = 0; j < N; j++){
              printf("%f ", array1[i][j]);
           }
        printf("\n");
        }
        */
        printf("\nTime to fast change index by row: ");
        dt_A = getCPU() - t0;
        (void) printf("\n%g\n\n", dt_A);


        k = 0.0;
        t1 = getCPU();
        /*appending matrix by column */
        array2 = malloc(N*sizeof(double));
        for(l=0; l<N; l++){
           array2[l] = malloc(N*sizeof(double));
        }

        for(j = 0; j < N; j++){
           for(i = 0; i < N; i++){
              k = k+1;
              array2[i][j] = k;
           }
        }
        /* printing matrix
        for(i = 0; i < N; i++){
           for(j = 0; j < N; j++){
              printf("%f ", array2[i][j]);
           }
        printf("\n");
        }
        */
        printf("\nTime to fast change index by column: ");
        dt_B = getCPU() - t1;
        (void) printf("\n%g\n\n", dt_B);

        file = fopen("execution_time.dat", "a");
        fprintf(file, "%d\t%f\t%f\t\n", N, dt_A, dt_B);
        fclose(file);
        return 0;
}
