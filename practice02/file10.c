#include <stdio.h>
int main() {
    int n;
    int proizv = 1;
    printf("Введите число: ");
    scanf ("%d", &n);

    for (int i = 1; i <= n; i++) {
        if ( i % 3 == 0) {
            proizv *= i;
        }
    }
    printf("%d\n", proizv);
    return 0;

}