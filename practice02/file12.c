#include <stdio.h>
int main () {
    int n;
    int sum = 0;
    printf("Введите число : ");
    scanf ("%d", &n);

    for (int i = -n; i < 0; i ++) {
        if (i < 0) {
            sum += i;
        }
    }
    printf ("%d\n", sum);

}