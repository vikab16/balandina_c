#include <stdio.h>

int main () {
    int n;
    int sum = 0;
    printf("Введите число: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if ( i % 5 == 0 ) {
            sum += i; 
    }
    }
    printf("%d\n", sum);
    return 0;
}