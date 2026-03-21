#include <stdio.h>
int main () {
    int n;
    int count = 0;
    printf("Введите число : ");
    scanf ("%d", &n);

    for (int i = 1; i <= n; i ++) {
        if ( i > 0) {
            count += 1;
        }
    }
    printf("%d\n", count);
    return 0;
}