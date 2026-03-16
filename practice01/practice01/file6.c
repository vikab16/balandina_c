#include <stdio.h>
int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    float average;
    average = ( (a + b + c) / 3.0f);
    printf("%f\n", average);
    return 0;
}