#include <stdio.h>
int main () {
    int n;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d чисел:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;
     

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}