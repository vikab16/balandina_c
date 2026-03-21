#include <stdio.h>

int main() {
    int N;
    printf("Введите число N: ");
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        if ( i % 3 == 0 ) {
            printf("Fizz\n");
        } else {
            printf("%d\n", i);
        }
    }
}