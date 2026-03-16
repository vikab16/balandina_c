#include <stdio.h>
int main() {
    int number;

    printf("Введите число: ");
    scanf("%d", &number);
    
    if (number % 2 == 0 && number % 3 == 0) {

        printf("Делится и на 2, и на 3: ДА\n");
    } else {
        printf("Делится и на 2, и на 3: НЕТ\n");
    }

    return 0;
}