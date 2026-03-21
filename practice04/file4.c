#include <stdio.h>
int main() {
    int n;
    int sum = 0;
    printf("Введите количество чисел массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d чисел\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("%d\n", sum);
    return 0;
}