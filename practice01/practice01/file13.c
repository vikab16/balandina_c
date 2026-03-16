#include <stdio.h>
int main() {
    int num;
    printf("Введите число: ");
    scanf("%d", &num);

    if ( num>=90 && num<=100 ) {
        printf("Оценка отлично: %d", num);
    }
   if ( num>=75 && num<=89 ) {
        printf("Оценка хорошо: %d", num);
    }
    if ( num>=60 && num<=74 ) {
        printf("Оценка удовлетворительно: %d", num);
    }
    if ( num<60 ) {
        printf("Оценка неудовлетворительно: %d", num);
    }
}