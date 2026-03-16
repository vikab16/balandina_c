#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    printf("Введите число: ");
    scanf("%d", &n);

    int result = n + INT_MAX;
    printf("INT_MAX это: %d\n", INT_MAX);
    printf("Результат переполнения: %d\n", result);
    return 0;

}