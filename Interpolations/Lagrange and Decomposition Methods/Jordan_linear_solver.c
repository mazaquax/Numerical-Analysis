#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//this function works in strong assumption of det(X) ne 0
double* jordan_main_throgh_matrix_1(double *X, double *y, int n){
    int i = 0, j = 0, k = 0,
        i_max, j_max;
    int *ind;
    ind = malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        ind[i] = i;
    double *y_sup, *a;
    y_sup = malloc(n*sizeof(double));
    a = malloc(n*sizeof(double));
    double max_elem = 0, t;

    for(i=0;i<n;i++) {
        y_sup[i] = y[i];
    }

    for(k=0;k<n;k++) {
        //Finding abs max elem
        for(i=k;i<n;i++) {
            for(j=k;j<n;j++) {
                if(fabs(X[i*n+j])>fabs(max_elem)) {
                    max_elem = X[i*n+j];
                    i_max = i;
                    j_max = j;
                }
            }
        }
        /*if(fabs(max_elem)<=10e-15) {
                return -1;
        }*/
        max_elem = 0;

        //Replacing max_elem to k,k position
            //Replacing strings
        t = y_sup[k];
        y_sup[k] = y_sup[i_max];
        y_sup[i_max] = t;
        for(j=k;j<n;j++) {
            t = X[k*n+j];
            X[k*n+j] = X[i_max*n+j];
            X[i_max*n+j] = t;
        }
            //Replacing columns
        j = ind[k]; //Replacing columns leads to replacing solution indexes. Remember that
        ind[k] = ind[j_max];
        ind[j_max] = j;

        for(i=0;i<n;i++){
            t = X[i*n+k];
            X[i*n+k] = X[i*n+j_max];
            X[i*n+j_max] = t;
        }

        //Gaussian step
            //Making k,k elem eq 1, i.e. dividing k-th string by k,k elem
        t = X[k*n+k];
        y_sup[k] /= t;
        for(j=k;j<n;j++) {
            X[k*n+j] /= t;
        }
            //Subtracting k-th string from those below, so that (k+1,k), ..., (n,k) elems would be eq to 0
        for(i=k+1;i<n;i++) {
            t = X[i*n+k];
            y_sup[i] -= y_sup[k]*t;
            for(j=k;j<n;j++) {
                X[i*n+j] -= X[k*n+j]*t;
            }
        }

        //Gaussian backward step
            //Subtracting k-th string from those above, so that (k-1,k), ..., (1,k) elems would be eq to 0
        for(i=0;i<k;i++) {
            t = X[i*n+k];
            y_sup[i] -= y_sup[k]*t;
            for(j=k;j<n;j++) {
                X[i*n+j] -= X[k*n+j]*t;
            }
        }
    }

    for(i=0;i<n;i++)
        a[ind[i]] = y_sup[i];

    free(y_sup);
    free(ind);

    return a;

    free(a);
}
