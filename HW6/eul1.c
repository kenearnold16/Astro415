#define NRANSI

void eul1(float **y, float **dydx, int n, int N, float *m, float x, float h, float **yout,
        void (*derivs)(float, float **, float **, int, int, float *))
{
        for (int i=1;i<=n;i=i+1){
            for (int j=1;j<=N;j++){
              yout[i][j]=y[i][j]+h*dydx[i][j];
            }
        }
}
#undef NRANSI
/* (C) Copr. 1986-92 Numerical Recipes Software ?421.1-9. */
