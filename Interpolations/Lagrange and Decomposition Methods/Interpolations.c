#include <math.h>

double interpolation_polinomial(double x, double *a, int n){
    double res = 0;
    int i = 0;
    for(i=0;i<n;i++) {
        res += a[i]*pow(x, i);
    }
    return res;
}

double Lagrange_interpolation_polinomial(double x, double *x_partition, double *y, int n){
    double res = 0, Phi_factor = 1;
    int i = 0, j = 0;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(j==i) continue;
            Phi_factor *= (x-x_partition[j])/(x_partition[i]-x_partition[j]);
        }
        res += y[i]*Phi_factor;
        Phi_factor = 1;
    }
    return res;
}
