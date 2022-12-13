#include <stdio.h>
#include <time.h>
#include <math.h>

double t0, t1, dt, k;
int i, j, N;
double getCPU(void)
{
     return (double) clock()/CLOCKS_PER_SEC;  /* convert to seconds */
}
/* Doing #1 on HW2 */
int main(void){

        printf("\nEnter the size of your array NxN: ");
        scanf("%d", &N);
        printf("%d", N);
        printf("\n");
        k = 0.0;
        double array1[N][N];
        double array2[N][N];

        t0 = getCPU();
        /*appending matrix by row */
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
        dt = getCPU() - t0;
        (void) printf("\n%g\n\n", dt);

        k = 0.0;
        t1 = getCPU();
        /*appending matrix by column */
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
        dt = getCPU() - t1;
        (void) printf("\n%g\n\n", dt);

    return 0;
}
