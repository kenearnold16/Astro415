# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// Function for sampling a 1-dimensional normal distribution using Box-Muller transform.
// Arguments are:
//  - the 2 uniform samples (generated in your own code using ran1.c)
//  - the mean
//  - the variance

float bmnorm(float u1, float u2, float mean, float var){
    float normal = (sqrtf(-2*var*logf(u1))*cosf(2*M_PI*u2)) + mean;
    return normal;
}
