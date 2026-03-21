#include <stdio.h>
int main () {
    int n;
    int max = 0;
    printf("Введите число : ");
    scanf ("%d", &n);

    for (int i = 1; i <= n; i ++) {
        if ( i > max) {
            max = i;
        }
    }
    printf("%d\n", max);
    return 0;
}