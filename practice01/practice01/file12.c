#include <stdio.h>
int main() {
    int a, b, c;
    printf("Введите три числа: ");
    scanf("%d %d %d", &a, &b, &c);

    if ( a > b && a > c) {
        printf("Максимум из трех чисел: %d\n", a);
    }
    else if ( b > c && b > a) {
        printf("Максимум: %d\n", b);
    }
    else if ( c > a && c > b) {
        printf("%d\n", c);
        return 0;

    }
}