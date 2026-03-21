#include <stdio.h>
int main() {
    int n;
    int found = 1;
    printf("Введите количество элемментов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d числа:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[i+1]) {
            found = 0;
            break;
        } 
    }
    if (found == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}