#include <stdio.h>
#include <stdlib.h>

#include "Validation_functions.h"
#include "Interpolations.h"

void results_to_file(FILE *file, double *x, double *y, double *a, int n){
    int i = 0;
    double h, x1, x2;
    void print_results_string(FILE *file, double x,
                              double *x_partition,
                              double *a, double *y, int n);
    fprintf(file, " x\t   ");
    fprintf(file, "f(x)\t    ");
    fprintf(file, "L(x)\t");
    fprintf(file, "P(x)\t");
    fprintf(file, "P(x)-f(x)   ");
    fprintf(file, "L(x)-f(x)\t");
    fprintf(file, "P(x)-L(x)\n");
    for(i=0;i<n-1;i++){
        print_results_string(file, x[i], x, a, y, n);
        //some additional points between nodes
        h = (x[i+1]-x[i])/3;
        x1 = x[i]+h;
        x2 = x[i]+2*h;
        //results for first additional point x1
        print_results_string(file, x1, x, a, y, n);
        //results for second additional point x2
        print_results_string(file, x2, x, a, y, n);
    }
    print_results_string(file, x[n-1], x, a, y, n);

}
void print_results_string(FILE *file, double x, double *x_partition, double *a, double *y, int n) {
    fprintf(file, "%lf  ", x);
    double true_value = validation_func(x, n);
    fprintf(file, "%lf  ", true_value);

    double Lagrange_interpolation_value = Lagrange_interpolation_polinomial(x, x_partition, y, n);
    double interpolation_value = interpolation_polinomial(x, a, n);

    fprintf(file, "%lf  ", Lagrange_interpolation_value);
    fprintf(file, "%lf  ", interpolation_value);
    fprintf(file, "%lf  ", interpolation_value-true_value);
    fprintf(file, "%lf  ", Lagrange_interpolation_value-true_value);
    fprintf(file, "%le\n", interpolation_value-Lagrange_interpolation_value);
}

