#include <math.h>

double Runge_func(double x){
    return 1/(25*x*x+1);
}

double validation_func(double x, int n){
    //return pow(x, n-1)-x;

    if(n>0) {
        double Runge_func(double x);
        return Runge_func(x);
    }

    /*if(n>0)
        return fabs(x);
    else
        return -1;*/
}
