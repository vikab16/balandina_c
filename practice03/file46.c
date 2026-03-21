#include <stdio.h>
int main () {
    int N;
    int count = 0;
    int zifra;
    printf("Введите число: ");
    scanf("%d", &N);

    while (N != 0) {
        zifra = N % 10;
        count += 1;
        N = N / 10;
    }
    printf("%d", count);
    return 0;
}