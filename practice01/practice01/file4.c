#include <stdio.h>

int main() {
    int num;       
    num = 25;     

    printf("Число: %d\n", num);
    printf("Адрес переменной: %p\n", (void*)&num);
    
    return 0;
}  