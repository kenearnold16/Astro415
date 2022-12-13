#include <stdio.h>
#include <math.h>
#include <string.h>
#include "./NumRec/nr.h"
#include "./NumRec/nrutil.h"

int i, j;
FILE *file;
FILE *orbit_file;
void lf2(float **y, float **dydx, int n, int N, float *m, float x, float h, float **yout,
        void (*derivs)(float, float **, float **, int, int, float *));

void eul1(float **y, float **dydx, int n, int N, float *m, float x, float h, float **yout,
        void (*derivs)(float, float **, float **, int, int, float *));

void deriv(float t, float **y, float **f, int n, int N, float *m){

     float check;
     /*for(i=1;i<=n;i++){
          printf("%f %f %f %f\n", m[i],y[i][1],y[i][3],y[i][5]);
          scanf("%d",&check);
     }*/
     float r;

     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if(i!=j){
              /*if(i == 50 && j == 50){
                printf("%d %d %f %f %f %f\n", i,j,m[i],y[i][1],y[i][3],y[i][5]);
                printf("%d %d %f %f %f %f\n", i,j,m[j],y[j][1],y[j][3],y[j][5]);
                scanf("%d",&check);
              }*/
              r = ((pow((y[i][1]-y[j][1]),2) + pow((y[i][3]-y[j][3]),2) + pow((y[i][5]-y[j][5]),2)));

              for(int k=1;k<=(N/2);k++){
                 f[i][2*k-1] = y[i][2*k];
                 f[i][2*k] = -(m[j]*(y[i][2*k-1] - y[j][2*k-1]))/(pow(r,1.5));
                 if(j == 1){
                    printf("%d %d %f %f %f %f\n", i,j,m[j],y[j][1],y[j][3],y[j][5]);
                    scanf("%d",&check);
                 }

              }/*
              printf("%d %d %f %f %f %f\n", i,j,m[i],y[i][1],y[i][3],y[i][5]);
              printf("%d %d %f %f %f %f\n", i,j,m[j],y[j][1],y[j][3],y[j][5]);
              scanf("%d",&check);*/
           }
         }
     }
}


int main(int argc,char *argv[]){
  if (argc != 2) {
    printf("Usage: %s rk4.txt|eu.txt|lf.txt \n",argv[0]);
    return 1;
  }

        int N=6;
        int n;
        scanf("%d", &n);

        int check;
        float r;
        float **y=matrix(1,n,1,N);
        float *m=vector(1,n);
        float **d=matrix(1,n,1,N);
        float time = 1000.0;

        float h=1;
        int Nsteps=time/h;

        file = fopen("initial_conditions.txt", "r");

        for(i=1;i<=n;i++){
           fscanf(file, "%f ", &m[i]);
           for(j=1;j<=(N/2);j++){
              fscanf(file, "%f %f", &y[i][2*j-1], &y[i][2*j]);
           }
           printf("%f %f %f %f %f %f %f \n", m[i], y[i][1], y[i][2], y[i][3], y[i][4], y[i][5], y[i][6]);
        }

        /*scanf("%d",&check);
        printf("%f %f %f %f %f %f %f \n", m[50], y[50][1], y[50][2], y[50][3], y[50][4], y[50][5], y[50][6]);

        scanf("%d",&check);
*/
        fclose(file);

        float t=0.0;

        orbit_file = fopen(argv[1], "w");

        for(i=1;i<=Nsteps;i++){
                deriv(t,y,d,n,N,m);

                for(j=1;j<=n;j++){
                    fprintf(orbit_file,"%d %f %f %f %f %f %f %f\n", j, m[j], t, y[j][1], y[j][3], y[j][5], y[j][2], y[j][4], y[j][6]);
                }

                t=i*h;
                if (strcmp(argv[1],"rk4.txt") == 0) rk4(y,d,n,N,m,t,h,y,*deriv);
                if (strcmp(argv[1],"lf.txt") == 0) lf2(y,d,n,N,m,t,h,y,*deriv);
                if (strcmp(argv[1], "eu.txt") == 0) eul1(y,d,n,N,m,t,h,y,*deriv);


        }
        fclose(orbit_file);
        return 1;
}
