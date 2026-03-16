#include <stdio.h>

int main() {
    int n;
    
    printf("Введите целое число: ");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    int last_digit = n < 0 ? -n % 10 : n % 10; 

    printf("Последняя цифра: %d\n", last_digit);
    
    return 0;
}