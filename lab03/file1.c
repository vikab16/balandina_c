#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    printf("Введите размер массива: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Ошибка: размер массива должен быть положительным числом\n");
        return 1;
    }

    int *arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Ошибка: память не выделена\n");
        return 1;
    }

    printf("Введите %d числа:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Элемент %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}