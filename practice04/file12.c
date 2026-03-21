#include <stdio.h>
    int main () {
    int n;
    int found = 0;
    int index = -1;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d чисел:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            index = i;
            break;          
        }
    }
    printf("%d\n", index);
    return 0;
}
