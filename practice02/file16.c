#include <stdio.h>
int main () {
    int n;
    int count = 0;
    printf("Введите число : ");
    scanf ("%d", &n);

    while ( n != 0 ) {
        count++;         
        scanf("%d", &n);
    }
 printf("%d\n", count);
 return 0;
}

    