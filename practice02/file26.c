#include <stdio.h>
int main () {
    int n;
    int sum = 0;
    int zifra;
    printf("Введите число:");
    scanf("%d", &n);

    while ( n != 0) {
        zifra = n % 10;
        sum += zifra;
        n /= 10;
    }
     printf("Сумма цифр: %d\n", sum);
    return 0;
}