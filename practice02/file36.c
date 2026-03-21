#include <stdio.h>
int main () {
    int n;
    int result;
    printf("Введите число: ");
    scanf("%d", &n);

    for (int i = 1; i <= 9; i++) {
        result = i * n;
        if (result > 30) {
            continue;
        } else {
            printf("%d\n", result);
        }
    }
return 0;
} 