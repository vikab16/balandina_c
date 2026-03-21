#include <stdio.h>
int main() {
    int num, digit;
    int count[10] = {0}; 
    printf("Введите число: ");
    scanf("%d", &num);

    if (num < 0) num = -num;
    if (num == 0) count[0] = 1;
    while (num > 0) {
        digit = num % 10;   
        count[digit]++;     
        num /= 10;    
    }
    printf("Результаты:\n");
    for (int i = 0; i < 10; i++) {
        if (count[i]) {
            printf("%d: %d\n", i, count[i]);
        }
    }

    return 0;
}