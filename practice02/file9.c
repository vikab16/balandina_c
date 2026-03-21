#include <stdio.h>
int main() {
    int n;
    printf("Введите число: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0) {
            continue;
        }
    printf("%d\n", i);
    }
    return 0;
} 