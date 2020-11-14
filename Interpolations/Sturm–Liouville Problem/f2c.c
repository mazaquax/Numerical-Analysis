#define _USE_MATH_DEFINES
#include <math.h>

void f2c(double *c, double *x, double *f, int N, double h);
void f2c(double *c, double *x, double *f, int N, double h) {
    int m = 0, k = 0;
    for(m=0;m<N;m++){
        c[m] = 0;
        for(k=1;k<N;k++){
            c[m] += f[k]*sin(M_PI*m*x[k]);
        }
        c[m] *= 2*h;
    }
}
