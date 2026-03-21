#include <stdio.h>
int main() {
    int n;
    int count = 0;
    printf("Введите число:");
    scanf("%d", &n);

    while (n != 0) {
        if ( n % 7 == 0) {
            count += 1;
        }
        scanf("%d", &n);
    }
    printf("%d\n", count);
    return 0;
}