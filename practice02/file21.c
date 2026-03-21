#include <stdio.h>
int main () {
    int n;
    int factorial = 1;
    printf("Введите число:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if ( i % 2 != 0) {
            factorial *= i;
        }
    }
    printf("%d\n", factorial);
    return 0;
}