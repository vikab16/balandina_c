#include <stdio.h>

int main() {
    int N;
    int count = 0;  
    printf("Введите N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if ((i * j) % 7 == 0) {
                count++;  
            }
        }
    }

    printf("Количество пар (i, j), где i * j делится на 7: %d\n", count);

    return 0;
}