#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Function_2B_interpolated.h"
#include "f2c.h"
#include "c2f.h"
#include "Results_to_file.h"
#include "Error_value.h"

int main(void) {
    FILE *results = fopen("results.txt", "w");
    int N = 100; //nodes quantity
    int i = 0;
    double h = 1/(N-0.5);
    int n = N+1;

    double *x, *f, *c;
    x = malloc((size_t)(n)*sizeof(double)); //nodes
    f = malloc((size_t)(n)*sizeof(double)); //f-values
    c = malloc((size_t)(N)*sizeof(double)); // coefficients of vector f in \phi basis

    x[0] = -h/2;
    for(i=1;i<n;i++){
        x[i] = x[i-1] + h;
    }
    //now x contains (N+1) nodes: x_0=-h/2,...,x_N=1

    /*for(i=0;i<n;i++){
        printf("%f ", x[i]);
    }
    printf("\n");*/

    for(i=0;i<n;i++){
        f[i] = func(x[i]);
    }
    //now f is a (N+1)-vector of f-values at the nodes x

    /*for(i=0;i<n;i++){
        printf("%f ", f[i]);
    }
    printf("\n");*/

    f2c(c, x, f, N, h);
    // now c contains coefficients: f=sum(\phi_k*c_k)
    // !!!ATTENTION!!! c[0] is fake, made for convenience
    /*for(i=0;i<n;i++) {
        printf("%f ", c2f(c, N, x[i]));
    }*/


    results_to_file(results, x, c, n);
    fclose(results);

    printf("When N is %d error equals %le", N, error_value(x, c, n));

    return 0;
}
