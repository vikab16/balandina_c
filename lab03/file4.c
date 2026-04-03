#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, m, i;
    
    printf("Введите размер массива n: ");
    scanf("%d", &n);
 
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    
    printf("Введите %d элементов массива:\n", n);
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nНачальный массив:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("\nВведите новый размер массива m больше %d: ", n);
    scanf("%d", &m);
    
    if (m <= n) {
        printf("Новый размер должен быть больше данного\n");
        free(arr);
        return 1;
    }
    
    int *temp = (int*)realloc(arr, m * sizeof(int));
    if (temp == NULL) {
        printf("Ошибка перевыделения памяти\n");
        free(arr);
        return 1;
    }
    arr = temp;
    
    printf("Введите %d новых элементов (с индекса %d до %d):\n", m - n, n, m - 1);
    for (i = n; i < m; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nОбновленный массив размер %d:\n", m);
    for (i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int new_size;
    printf("\nВведите новый размер после уменьшения меньше %d: ", m);
    scanf("%d", &new_size);
    
    if (new_size >= m) {
        printf("Новый размер должен быть меньше данного\n");
    } else {
        temp = (int*)realloc(arr, new_size * sizeof(int));
        if (temp == NULL && new_size > 0) {
            printf("Ошибка при уменьшении памяти\n");
        } else {
            arr = temp;
            printf("\nМассив после уменьшения до %d элементов:\n", new_size);
            for (i = 0; i < new_size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    
    free(arr);
    
    return 0;
}