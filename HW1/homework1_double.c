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
     (void) printf("\nTime to run the function add_five_double() %g sec ", dt);
     printf("\ndone with +5 %d times ", n);
     printf("\nResult = %f \n", out);
}

/* function to subtract five as double */
void minus_five_double(int n) {
     out = 0.0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out - 5.0;
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function minus_five_double() %g sec ", dt);
     printf("\ndone with -5 %d times ", n);
     printf("\nResult = %f \n ", out);
}

/* function to multiply by 1 as double */
void times_one_double(int n) {
     out = 1.0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out*1.000001;
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function times_one_double() %g sec ", dt);
     printf("\ndone with *1 %d times ", n);
     printf("\nResult = %f \n", out);
}

/* function to divide by 1 as double */
void divide_one_double(int n) {
     out = 1.0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out/1.000001;
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function divide_one_double() %g sec ", dt);
     printf("\ndone with /1 %d times ", n);
     printf("\nResult = %f \n", out);
}

/* function to sqrt 1 as double */
void sqrt_one_double(int n) {
     out = 1.1;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = sqrt (out);
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function sqrt_one_double() %g sec ", dt);
     printf("\ndone with sqrt() %d times ", n);
     printf("\nResult = %f \n", out);
}

/* function to power of 0.5 as double */
void pow_one_double(int n) {
     out = 1.1;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = pow (out,0.5);
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function sqrt_one_double() %g sec ", dt);
     printf("\ndone with pow(out,x) %d times ", n);
     printf("\nResult = %f \n", out);
}

int main(void)
{
     printf("\nEnter an integer n: ");
     scanf("%d", &n_input);

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
