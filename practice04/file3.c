#include <stdio.h>
int main() {
    int n;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d чисел\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min = arr[0], index = 0;
    for (int i = 1; i < n; i++) {
        if ( arr [i] < min) {
            min = arr [i];
            index = i;
        }
    }
    printf("Min: %d, index: %d\n", min, index);
    return 0;
}