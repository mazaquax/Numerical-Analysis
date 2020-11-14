#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Function_2B_interpolated.h"
#include "c2f.h"

double error(double x, double *c, int n);

double error_value(double *x, double *c, int n);
double error_value(double *x, double *c, int n) {
    int i = 0;
    double h, x1, x2;
    double error_value = 0, error0, error1, error2;

    //double error(double x, double *c, int n);

    for(i=1;i<n-1;i++){
        h = (x[i+1]-x[i])/3;
        x1 = x[i]+h;
        x2 = x[i]+2*h;

        error0 = error(x[i], c, n);
        error1 = error(x1, c, n);
        error2 = error(x2, c, n);

        if(error_value < error0)
            error_value = error0;
        if(error_value < error1)
            error_value = error1;
        if(error_value < error2)
            error_value = error2;
        //printf("%lf\n", error_value);
    }
    return error_value;
}

double error(double x, double *c, int n) {
    return fabs(c2f(c, n-1, x)-func(x));
}
