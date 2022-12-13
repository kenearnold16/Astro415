#include <stdio.h>
#include <time.h>
#include <math.h>

double t0, dt, out;
int i, n_input;

double getCPU(void)
{
     return (double) clock()/CLOCKS_PER_SEC;  /* convert to seconds */
}

/* function to add five as double */
void add_five_double(int n) {
     out = 0.0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out + 5.0;
     }
     dt = getCPU() - t0;
     (void) printf("\n%g ", dt);
}

/* function to subtract five as double */
void minus_five_double(int n) {
     out = 0.0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out - 5.0;
     }
     dt = getCPU() - t0;
     (void) printf("\n%g ", dt);
}

/* function to multiply by 1 as double */
void times_one_double(int n) {
     out = 1.0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out*1.000001;
     }
     dt = getCPU() - t0;
     (void) printf("\n%g ", dt);
}

/* function to divide by 1 as double */
void divide_one_double(int n) {
     out = 1.0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out/1.000001;
     }
     dt = getCPU() - t0;
     (void) printf("\n%g ", dt);
}

/* function to sqrt 1 as double */
void sqrt_one_double(int n) {
     out = 1.1;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = sqrt (out);
     }
     dt = getCPU() - t0;
     (void) printf("\n%g ", dt);
}

/* function to power of 0.5 as double */
void pow_one_double(int n) {
     out = 1.1;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = pow (out,0.5);
     }
     dt = getCPU() - t0;
     (void) printf("\n%g \n", dt);
}

int main(void)
{
     scanf("%d", &n_input);
     printf("%d", n_input);

     /* Time to add 5 as double */
     add_five_double(n_input);
     /* Time to subtract 5 as double */
     minus_five_double(n_input);
     /* Time to multiply by 1 as double */
     times_one_double(n_input);
     /* Time to divide by 1 as double */
     divide_one_double(n_input);
     /* Time to sqrt of 1 as double */
     sqrt_one_double(n_input);
     /* Time to power of 0.5 as double */
     pow_one_double(n_input);

     return 0;
}
