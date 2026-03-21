#include <stdio.h>
int main() {
    int n;
    int kvadrat = 1;
    printf("Введите число:");
    scanf("%d", &n);

    while (n != 0) {
        if ( n % 2 == 0 ) {
             kvadrat = n * n;
             printf("%d\n", kvadrat);
        }
     scanf("%d", &n);
    }
    return 0;
}