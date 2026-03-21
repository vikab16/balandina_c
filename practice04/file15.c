#include <stdio.h>
int main() {
    int n;
    int sum = 0;
    printf("Введите количество: ");
    scanf("%d", &n);

    int arr[n];
    printf("введите %d числа: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i += 2) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    return 0;

}