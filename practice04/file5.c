#include <stdio.h>
int main () {
    int n;
    int count = 0;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            count += 1;
        }
    }
    printf("%d\n", count);
    return 0;
}