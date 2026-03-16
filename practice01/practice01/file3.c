#include <stdio.h>

int main() {
    printf("Размер типа int: %zu байт\n", sizeof(int));
    printf("Размер типа float: %zu байт\n", sizeof(float));
    printf("Размер типа double: %zu байт\n", sizeof(double));
    printf("Размер типа char: %zu байт\n", sizeof(char));

    return 0;
}