#include <stdio.h>

int main() {
    int num1, num2;

    printf("Введите первое число: ");
    scanf("%d", &num1);

    printf("Введите второе число: ");
    scanf("%d", &num2);

    printf("Сумма: %d\n", num1 + num2);
    printf("Разность: %d\n", num1 - num2);
    printf("Произведение: %d\n", num1 * num2);

    if (num2 != 0) {
        printf("Результат целочисленного деления: %d\n", num1 / num2);
    } else {
        printf("Ошибка: деление на ноль невозможно!\n");
    }

    return 0;
}