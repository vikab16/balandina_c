#include <stdio.h>
int main () {
    int n;
    int found = 0;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите %d числа: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if ( arr[i] % 2 == 0) {
            found = 1;
            break;
        }
} 
    if ( found == 1 ){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}