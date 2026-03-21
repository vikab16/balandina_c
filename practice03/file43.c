#include <stdio.h>

int main() {
    int N, orig, revers = 0, lastzifra;
    printf("Введите число: ");
    scanf("%d", &N);

    orig = N;

    while (N != 0) {
        lastzifra = N % 10;           
        revers = revers * 10 + lastzifra; 
        N = N / 10;  
    }

    if (orig == revers) {
        printf("%d — палиндром!\n", orig);
    } else {
        printf("%d — не палиндром.\n", orig);
    }

    return 0;
}