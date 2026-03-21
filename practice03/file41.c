#include <stdio.h>
int main() {
    int N;
    int zifra;
    int sum = 0;
    printf("Введите число: ");
    scanf("%d", &N);

    while (N != 0) {
        zifra = N % 10;
        sum += zifra;
        N = N / 10; 
    }
    printf("%d\n", sum);
    return 0;
}