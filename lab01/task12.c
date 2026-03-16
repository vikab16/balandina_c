#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Введите трёхзначное число: ");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка ввода.\n");
        return 1; 
    }

    n = abs(n); 
    if (n < 100 || n > 999) {
        printf("Ошибка: введите трёхзначное число.\n");
        return 1; 
    }

    int hundreds = n / 100;
    int tens = (n / 10) % 10;
    int units = n % 10;

 
    printf("Сотни: %d\nДесятки: %d\nЕдиницы: %d\n", hundreds, tens, units);
    
    return 0; 
}