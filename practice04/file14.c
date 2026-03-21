#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    int second_max;
    int found = 0;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d чисел\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);   
    }
    int max = arr[0];

    for(int i = 0; i < n; i++){
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < max) {
            second_max = arr [i];
        }
    }

    for(int i = 0; i < n; i++) {
        if ( second_max < max && second_max > arr[i]) {
            found = 1;
        }
    }

    if (found == 1) {
        printf("%d\n", second_max);
    } else {
        printf("0");
    }
    return 0;
}