#include <stdio.h>
int main () {
int N, reversed = 0, remainder;
printf("Введите число: ");
scanf("%d", &N);

while ( N != 0) {
    remainder = N % 10;
    reversed = reversed * 10 + remainder;
    N = N / 10;
}
printf("%d", reversed);
return 0;
}
 