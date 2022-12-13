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

void deriv(float t, float **y, float **f, int n, int N, float *m){

     float check;

     float r;
     float eps = 30.0;

     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if(i!=j){
              r = ((pow((y[i][1]-y[j][1]),2) + pow((y[i][3]-y[j][3]),2) + pow((y[i][5]-y[j][5]),2)));

              for(int k=1;k<=(N/2);k++){
                 f[i][2*k-1] = y[i][2*k];
                 f[i][2*k] = -(m[j]*(y[i][2*k-1] - y[j][2*k-1]))/(pow(r,1.5) + pow(eps,2));
              }
           }
         }
     }
}


int main(int argc,char *argv[]){
  if (argc != 2) {
    printf("Usage: %s rk4.txt|lf.txt \n",argv[0]);
    return 1;
  }

        int N=6;
        int n;
        scanf("%d", &n);

        int check;
        float r;
        float R = 1000.0;
        float **y=matrix(1,n,1,N);
        float *m=vector(1,n);
        float **d=matrix(1,n,1,N);
        float time = 10.0;

        float h = 0.1;
        printf("%f\n",h);
        int Nsteps=time/h;

        file = fopen("initial_conditions.txt", "r");

        for(i=1;i<=n;i++){
           fscanf(file, "%f ", &m[i]);
           for(j=1;j<=(N/2);j++){
              fscanf(file, "%f %f", &y[i][2*j-1], &y[i][2*j]);
           }
        }

        fclose(file);

        float t=0.0;

        orbit_file = fopen(argv[1], "w");

        for(i=1;i<=Nsteps;i++){
                deriv(t,y,d,n,N,m);

                for(j=1;j<=n;j++){
                    fprintf(orbit_file,"%d %f %f %f %f %f %f %f %f\n", j, m[j], t, y[j][1], y[j][3], y[j][5], y[j][2], y[j][4], y[j][6]);
                }

                t=i*h;
                if (strcmp(argv[1],"rk4.txt") == 0) rk4(y,d,n,N,m,t,h,y,*deriv);
                if (strcmp(argv[1],"lf.txt") == 0) lf2(y,d,n,N,m,t,h,y,*deriv);

        }
        fclose(orbit_file);
        return 1;
}
