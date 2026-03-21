#include <stdio.h>
int main () {
    int n;
    int sum = 0;
    int count;
    double sr;

    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d чисел\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    for(int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            count += 1;
        }
    }
    sr = sum / count;
    printf("%f\n", count);
    return 0;
}