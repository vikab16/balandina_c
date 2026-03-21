#include <stdio.h>
int main() {

int N;
int zifra;
int a;
printf("Введите число: ");
scanf("%d", &N);

while (N != 0) {
     if (zifra % 2 != 0) {
            a = 0;
            break; 
        }
         N = N / 10;
    }
    if ( a != 0)  {
        printf("Число состоит из четных чисел");
    } else {
        printf("Число сотоит из нечетных чисел");
    }
    return 0;
}