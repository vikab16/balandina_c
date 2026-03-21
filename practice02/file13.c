#include <stdio.h>
int main () {
    int n;
    printf("Введите число : ");
    scanf ("%d", &n);

    for (int i = 1; i <= n; i ++) {
        if ( i < 1 ) {
            continue;
        } else if ( i > 10) {
         printf("%d\n", i);
        }
    }
    return 0;
    } 