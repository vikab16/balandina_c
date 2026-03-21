#include <stdio.h>

int main() {
    int N;
    printf("Введите N: ");
    scanf("%d", &N);

    printf("Простые числа от 1 до %d:\n", N);
    for (int num = 2; num <= N; num++) {
        int is_prime = 1; 

        for (int divisor = 2; divisor < num; divisor++) {
            if (num % divisor == 0) {
                is_prime = 0;  
                break;  
            }
        }

        if (is_prime) {
            printf("%d ", num);
        }
    }

    printf("\n");
    return 0;
}
