#include <stdio.h>

int main() {
    float celsius;
    printf("Введите температуру в Цельсиях: ");
    scanf("%f", &celsius);

    float fahrenheit = celsius * 1.8 + 32;
    float kelvin = celsius + 273.15;

    printf("%.2f C = %.2f F\n", celsius, fahrenheit);
    printf("%.2f C = %.2f K\n", celsius, kelvin);

    return 0;
}