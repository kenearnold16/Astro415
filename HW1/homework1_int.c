#include <stdio.h>
#include <time.h>

double t0, dt;
int out, i, n_input;

double getCPU(void)
{
     return (double) clock()/CLOCKS_PER_SEC;  /* convert to seconds */
}

/* function to add five as int */
double add_five_int(int n) {
     out = 0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out + 5;
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function add_five_int() %g sec ", dt);
     printf("\ndone with +5 %d times ", n);
     printf("\nResult = %d \n", out);
}

/* function to subtract five as int */
double minus_five_int(int n) {
     out = 0;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out - 5;
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function minus_five_int() %g sec ", dt);
     printf("\ndone with -5 %d times ", n);
     printf("\nResult = %d \n ", out);
}

/* function to multiply by 1 as int */
double times_one_int(int n) {
     out = 1;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out*1;
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function times_one_int() %g sec ", dt);
     printf("\ndone with *1 %d times ", n);
     printf("\nResult = %d \n", out);
}

/* function to divide by 1 as int */
double divide_one_int(int n) {
     out = 1;
     t0 = getCPU();
     for(i = 0; i < n; i++){
         out = out/1;
     }
     dt = getCPU() - t0;
     (void) printf("\nTime to run the function divide_one_int() %g sec ", dt);
     printf("\ndone with /1 %d times ", n);
     printf("\nResult = %d \n", out);
}

int main(void)
{
     printf("Enter an integer n: ");
     scanf("%d", &n_input);

     /* Time to add 5 as int */
     add_five_int(n_input);
     /* Time to subtract 5 as int */
     minus_five_int(n_input);
     /* Time to multiply by 1 as int */
     times_one_int(n_input);
     /* Time to divide by 1 as int */
     divide_one_int(n_input);

     return 0;


}
