#include <stdio.h>

int main () {
    printf("Hello, world!\n");

    int x = 5;
    printf("Адрес переменной x: %p\n", (void*)&x);
    return 0;
}