#include <stdio.h>
int main () {
    int n;
    int min = 9999999;
    printf("Введите число : ");
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        if ( i % 2 == 0 && i < min) {
            min = i;
        }
    }
    printf("%d\n", min);
    return 0;
    }