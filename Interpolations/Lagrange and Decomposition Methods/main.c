#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Interpolations.h"
#include "Jordan_linear_solver.h"
#include "Partitions.h"
#include "Results_to_file.h"
#include "Validation_functions.h"

//double validation_func(double x, int n);

int main() {
    int n = 7;
    int i=0, j = 0;

    double *x, *y;
    x = malloc(n*sizeof(double)); //points from [-1;1]
    y = malloc(n*sizeof(double)); //values of a function to be interpolated at x'es

    //x'es sampling
    //uniform_partition(x, n);
    Chebyshev_partition(x, n);

    for(i=0;i<n;i++) {
        y[i] = validation_func(x[i], n);
    }

    double *X; //Vandermonde matrix of x_i'es powers
    X = malloc(n*n*sizeof(double));
    double *a; // interpolation polynomial coefficients; a_i*x^i, i=0, ..., n-1
    a = malloc(n*sizeof(double));

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            X[i*n+j] = pow(x[i], j);
        }
    }

    //linear system solving
    a = jordan_main_throgh_matrix_1(X, y, n);
    // Now a contains interpolation coefficients

    FILE *results = fopen("results.txt", "w");
    results_to_file(results, x, y, a, n);
    fclose(results);

    free(x);
    free(y);
    free(a);
    free(X);

    return 0;
}
