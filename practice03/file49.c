#include <stdio.h>
int main() {
    int N;
    int sum = 0;
    int num;
    int temp;
    int zifra;
    printf("Введите число: ");
    scanf("%d", &N);

    num = N + 1;
    
    while (1) {  
        sum = 0;
        temp = num;
        while (temp > 0) {
            sum += temp % 10;  
            temp /= 10;       
        }
            if  (num % sum == 0) {
            break; 
        }
        num++;  
    }
    printf("Ответ: %d\n", num);
    return 0;
}

