#include <stdio.h>
int main() {
    int n;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d чисел\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
}
int temp = arr[0];
arr[n - 1] = temp;

for(int i = 0; i < n; i++) {
    arr[i]=arr[i-1];
}

printf("%d\n", arr[i]);
return 0;
}