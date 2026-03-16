#include <stdio.h>

int main() {
    float n1, n2;
    char op;

    printf("Введите первое число, знак (+ - * /) и второе число: ");
    scanf("%f %c %f", &n1, &op, &n2);

    switch (op) {
        case '+': printf("Результат: %.2f\n", n1 + n2); break;
        case '-': printf("Результат: %.2f\n", n1 - n2); break;
        case '*': printf("Результат: %.2f\n", n1 * n2); break;
        case '/': 
            if (n2 != 0) 
                printf("Результат: %.2f\n", n1 / n2);
            else 
                printf("Ошибка: деление на ноль!\n");
            break;
        default: printf("Ошибка: неизвестная операция!\n");
    }

    return 0;
}