#define NRANSI
#include "./NumRec/nrutil.h"

void rk4(float **y, float **dydx, int n, int N, float *m, float x, float h, float **yout,
        void (*derivs)(float, float **, float **, int, int, float *))
{
        int i, j;
        float xh,hh,h6,**dym,**dyt,**yt;

        dym=matrix(1,n,1,N);
        dyt=matrix(1,n,1,N);
        yt=matrix(1,n,1,N);
        hh=h*0.5;
        h6=h/6.0;
        xh=x+hh;
        for(i=1;i<=n;i++){
           for (j=1;j<=N;j++){
                yt[i][j]=y[i][j]+hh*dydx[i][j];
           }
           (*derivs)(xh,yt,dyt,n,N,m);
           for (j=1;j<=N;j++){
                yt[i][j]=y[i][j]+hh*dyt[i][j];
           }
           (*derivs)(xh,yt,dym,n,N,m);
           for (j=1;j<=N;j++){
                yt[i][j]=y[i][j]+h*dym[i][j];
                dym[i][j] += dyt[i][j];
           }
           (*derivs)(x+h,yt,dyt,n,N,m);
           for (j=1;j<=N;j++){
                yout[i][j]=y[i][j]+h6*(dydx[i][j]+dyt[i][j]+2.0*dym[i][j]);
           }
         }
         free_matrix(yt,1,n,1,N);
         free_matrix(dyt,1,n,1,N);
         free_matrix(dym,1,n,1,N);

}
#undef NRANSI
/* (C) Copr. 1986-92 Numerical Recipes Software ?421.1-9. */
