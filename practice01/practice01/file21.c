#include <stdio.h>

int main() {
    char ch;
    printf("Введите любой символ: ");
    scanf(" %c", &ch); 

    if (ch >= '0' && ch <= '9') {
        printf("Это цифра!\n");
    } 
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        printf("Это буква!\n");
    } 
    else {
        printf("Это спецсимвол или другой знак.\n");
    }
    return 0;
}