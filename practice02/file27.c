#include <stdio.h>
int main () {
    int n;
    int zifra;
    printf("Введите число:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if ( i % 17 == 0 ) {
            zifra = i;
            break;
        }
    }
    printf("%d\n", zifra);
    return 0;
}