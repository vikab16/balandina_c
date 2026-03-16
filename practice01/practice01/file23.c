#include <stdio.h>

int main() {
    int a, b;
    printf("Введите два числа a и b: ");
    scanf("%d %d", &a, &b);

    if (a > b) {
        printf("%d больше чем %d\n", a, b);
    } else if (a < b) {
        printf("%d меньше чем %d\n", a, b);
    } else {
        printf("Числа равны\n");
    }

    return 0;
}