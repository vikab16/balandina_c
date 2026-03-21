#include <stdio.h>
int main() {
    int n;
    int max;
    printf("Введите число: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Введите %d чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        }

    max = arr[0];

    for ( int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } 
    }

    printf("%d\n", max);
    return 0;
}