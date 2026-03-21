#include <stdio.h>

int main () {
    int n;
    printf("Введите число: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
     int kvadrat = i * i;
    if (kvadrat > 50 ) {
        printf("%d\n", kvadrat);
    }
}
return 0;
}