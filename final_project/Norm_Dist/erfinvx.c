# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*  Approximation of the inverse error function using the Maclaurin Series.
    Ended up being useless because the Box-Muller Trransform is way better time-wise.
    BUT this is cooler in my opinion.
    Arguments are:
        - the number of terms in the sum (N)
        - the value for which to compute the inverse error function output (only for |x| < 1).
*/

float erfinvx(int N, float x){
    int k, m; // indices for sum
    float* c = malloc(N*sizeof(float)); // array of coefficients for summation
    float erfinv; // define variable for erfinv output

    c[0] = 1; // initial coefficient
    for(k = 1; k <= N; k++){
        for(m = 0; m < k; m++){
            c[k] = c[m]*c[k - 1 - m]/(((float)m + 1)*(2*(float)m + 1)); // coefficients for each term in sum
        }
        erfinv += c[k]*powf(sqrtf(M_PI/4)*x, 2*(float)k + 1)/(2*(float)k + 1); // sum term
    }

    return erfinv;
}