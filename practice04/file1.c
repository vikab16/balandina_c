#include <stdio.h>

int main(void) {
    int arr[10];
    printf("Введите 10 целых чисел: ");
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 9; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n"); 
    
    return 0;
}