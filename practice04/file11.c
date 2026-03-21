#include <stdio.h>
int main () {
    int n;
    int count = 0;


    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("введите %d числа: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Введите число для подсчета: ");
    scanf("%d", &x);

    for(int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count += 1;
        }
    }
    if (count != 0) {
        printf("%d\n", count);
    } else {
        printf("0");
    }
    return 0;
}