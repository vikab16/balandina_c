#include <stdio.h>
int main () {
    int a, b, c;
    printf("Введите три числа: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b == c) {
        printf("%d + %d равно %d\n", a, b, c);
    } else {
        printf("не совпало\n");
    }
    return 0;
}