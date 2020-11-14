#define _USE_MATH_DEFINES
#include <math.h>

double c2f(double *c, int N, double x);
double c2f(double *c, int N, double x) {
    double y = 0;
    int m = 0;
    for(m=1;m<N;m++) {
        y += c[m]*sin(M_PI*m*x);
    }
    return y;
}
