#include <stdio.h>
int main() {
    int a, b, result;
    printf("Введите первое число: ");
    scanf("%d", &a);
    printf("Введите второе число: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("Ошибка: на ноль делить нельзя!\n");
    } else {
        result = a % b;
        printf("Остаток от деления %d на %d равен: %d\n", a, b, result);
    }
    return 0;
}