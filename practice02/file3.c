#include <stdio.h>
int main () {
    int n;
    printf("Введите число: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if ( i % 3 == 0 ) {
            printf("%d\n", i);
        }
    }
}