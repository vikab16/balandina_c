#include <stdio.h>
int main() {
    int n;
    int sum = 0;
    int count;
    double sr;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d числа\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        count += 1;
    }
    sr = sum / count;
    printf("%f\n", sr);
    return 0;
}