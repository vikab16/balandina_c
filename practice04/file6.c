#include <stdio.h>
int main () {
    int n;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d чисел\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = 0;
        } 
    }
        for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
    
}

