#include <stdio.h>
#include <limits.h>

int main () {
    int x = 2147483647;
    printf("x = %d\n", x);
    x = x + 1;
    printf("x + 1 = %d\n", x);
    return 0;
}