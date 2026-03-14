#include <stdio.h>

int main() {
    int n;

    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Количество элементов должно быть положительным.\n");
        return 1;
    }

    int array[n]; 
    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }

    double average = (double)sum / n;

    printf("Сумма: %d\n", sum);
    printf("Среднее значение: %.2f\n", average);

    return 0;
}