#include <stdio.h>
int main() {
    int a,b;
    printf("Введите два числа: ");
    scanf("%d %d", &a, &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Результат: a = %d, b = %d\n", a, b);
    return 0;
}