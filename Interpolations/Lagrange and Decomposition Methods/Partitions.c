#define _USE_MATH_DEFINES
#include <math.h>

void uniform_partition(double *x, int n){
    int i = 0;
    for(i=0;i<n;i++) {
        x[i] = -1+2*i/(double)(n-1);
    }
}

void Chebyshev_partition(double *x, int n){
    int i = 0;
    for(i=0;i<n;i++) {
        x[n-i-1] = cos((2*(i+1)-1)*M_PI/(2*n));
    }
}
