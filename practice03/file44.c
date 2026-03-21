#include <stdio.h>
int main() {
    int N;
    int max = 0;
    int zifra;
    printf("Введите число: ");
    scanf("%d", &N);

    while (N != 0) {
        zifra = N % 10;
        if ( zifra > max) {
            max = zifra;
        }
        N = N / 10;
    }
    printf("%d\n", max);
    return 0;
}