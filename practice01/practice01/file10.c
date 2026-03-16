#include <stdio.h>

int main() {
    int n;
    printf("Введите целое число n: ");
    scanf("%d", &n);

    printf("n %% 1 = %d\n", n % 1);
    printf("n | 1 = %d\n", n | 1);
    printf("n ^ 1 = %d\n", n ^ 1);
    printf("~n = %d\n", ~n);

    return 0;
}