#include <stdio.h>

int main() {
    int a, b, c;
    printf("Введите числа a, b и c: ");
    scanf("%d %d %d", &a, &b, &c);

    float result = ((a + b) * c) / 2.0;

    printf("Результат ((%d + %d) * %d) / 2 = %.2f\n", a, b, c, result);

    return 0;
}