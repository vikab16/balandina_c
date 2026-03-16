#include <stdio.h>

int main() {
    int number;
    printf("Введите целое число: ");
    scanf("%d", &number);
    if (number % 2 == 0) {
        printf("Число %d — чётное.\n", number);
    } else {
        printf("Число %d — нечётное.\n", number);
    }

    return 0;
}