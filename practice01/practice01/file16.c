#include <stdio.h>
int main() {
    int x;
    printf("Введите число: ");
    scanf("%d", &x);
    
    if (x>0) {
        printf("%d\n", x * x);
    }
    else if (x == 0) {
        printf("%d", 0);
    }
    else if (x<0) {
        printf("%d", -x);
    }
    return 0;
}