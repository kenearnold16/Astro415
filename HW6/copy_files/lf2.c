#define NRANSI

void lf2(float **y, float **dydx, int n, int N, float *m, float x, float h, float **yout,
        void (*derivs)(float, float **, float **, int, int, float *))
{
        int i,j;
        float xh,hh;

        hh=h*0.5;
        xh=x+hh;
        for(i=1;i<=n;i=i+1){
           for (j=1;j<=N;j=j+2){
                yout[i][j+1]=y[i][j+1]+hh*dydx[i][j+1];
                yout[i][j]=y[i][j]+h*yout[i][j+1];
                (*derivs)(xh,yout,dydx,n,N,m);
                yout[i][j+1]=yout[i][j+1]+hh*dydx[i][j+1];
           }
        }
}
#undef NRANSI
/* (C) Copr. 1986-92 Numerical Recipes Software ?421.1-9. */
