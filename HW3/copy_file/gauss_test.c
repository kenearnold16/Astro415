# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "./NumRec/nr.h"
# include "./NumRec/nrutil.h"

int main()
{
    float **a = matrix(1, 3, 1, 3);
    float **b = matrix(1, 3, 1, 1);
    float matfil[] = {-3.0, 2.0, -5.0, 2.0, -3.0, 4.0, 1.0, 1.0, 1.0};

    int N = sqrt(sizeof(matfil)/sizeof(matfil[0]));
    printf("%d %f %f\n", N, matfil[0],matfil[8]);

    for(int i = 1;i<4; i++){
       printf("\n");
       for(int j = 1;j<4;j++){
          printf("%f\t", b[i][j]);
       }
    }
    printf("\n");

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            a[i][j] = matfil[j+3*(i-1)-1];
        }
    }
    b[1][1] = -14;
    b[2][1] = 10;
    b[3][1] = 4;

    for(int i = 1;i<4; i++){
       printf("\n");
       for(int j = 1;j<4;j++){
          printf("%f\t", b[i][j]);
       }
    }
    printf("\n");
    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            printf("\n%f ", a[i][j]);
        }
    }
    gaussj(a,N,b,1);

    printf("\n %f %f %f\n",b[1][1],b[2][1],b[3][1]);

}
