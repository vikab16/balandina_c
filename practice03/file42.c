#include <stdio.h>
int main () {
    int N;
    int zifra;
    int proizv = 1;
    printf("Введите число: ");
    scanf("%d", &N);

    while (N != 0 ) {
        zifra = N % 10;
        if ( zifra != 0 ) {
            proizv *= zifra;
        }
        N = N / 10;
    }
    printf("%d\n", proizv);
    return 0;
}