#include <stdio.h>

int main() {
    int N, K;
    printf("Введите N: ");
    scanf("%d", &N);
    printf("Введите K: ");
    scanf("%d", &K);

    printf("Пары (i, j), где i + j = %d:\n", K);

    for (int i = 1; i <= N; i++) {
        int j = K - i;
        if (j >= 1 && j <= N) {
            printf("(%d, %d)\n", i, j);
        }
    }

    return 0;
}