#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Function_2B_interpolated.h"
#include "c2f.h"

void print_results_string(FILE *file, double x, double *a, int n);

void results_to_file(FILE *file, double *x, double *a, int n);
void results_to_file(FILE *file, double *x, double *a, int n){
    int i = 0;
    double h, x1, x2;

    fprintf(file, " x\t   ");
    fprintf(file, "f(x)\t    ");
    fprintf(file, "c2f(x)\t");
    fprintf(file, "|c2f(x)-f(x)|\n");

    for(i=1;i<n-1;i++){
        print_results_string(file, x[i], a, n);
        //some additional points between nodes
        h = (x[i+1]-x[i])/3;
        x1 = x[i]+h;
        x2 = x[i]+2*h;
        //results for first additional point x1
        print_results_string(file, x1, a, n);
        //results for second additional point x2
        print_results_string(file, x2, a, n);
    }
    print_results_string(file, x[n-1], a, n);

}
void print_results_string(FILE *file, double x, double *a, int n) {
    double true_value = func(x);
    double c2f_value = c2f(a, n-1, x);
    fprintf(file, "%lf  ", x);

    fprintf(file, "%lf  ", true_value);
    fprintf(file, "%lf  ", c2f_value);
    fprintf(file, "%le\n", fabs(c2f_value-true_value));
}


