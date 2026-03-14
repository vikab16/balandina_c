#include <stdio.h>
int main () {
    double x;
    if (scanf("%lf", &x) !=1) return 0;

    double expr1 = x*x + 2*x + 1;
    double expr2 = 4*x;

    printf("x^2 + 2x + 1 = %g\n", expr1);
    printf("(x+1)^2 - (x-1)^2 = %g\n", expr2);
    return 0;
}