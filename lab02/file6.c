#include <stdio.h>

union Data {
    int int_value;
    float float_value;
    char char_value;
};

struct TypedData {
    union Data data;        
    int type;  
};

int main() {
    union Data myData;

    printf("Демонстрация работы объединения\n");

    myData.int_value = 42;
    printf("Записала int: %d\n", myData.int_value);

    myData.float_value = 3.14;
    printf("Записала float: %.2f\n", myData.float_value);
    printf("Теперь int_value показывает: %d (мусор)\n", myData.int_value);
    myData.char_value = 'A';
    printf("Записала char: %c\n", myData.char_value);
    printf("Теперь float_value показывает: %.2f (мусор)\n", myData.float_value);

    printf("\nИспользование структуры с union\n");

    struct TypedData td;

    td.data.int_value = 100;
    td.type = 1;

    if (td.type == 1) {
        printf("Хранится int: %d\n", td.data.int_value);
    } else if (td.type == 2) {
        printf("Хранится float: %.2f\n", td.data.float_value);
    } else if (td.type == 3) {
        printf("Хранится char: %c\n", td.data.char_value);
    }

    td.data.float_value = 2.718;
    td.type = 2;  

     if (td.type == 1) {
        printf("Хранится int: %d\n", td.data.int_value);
    } else if (td.type == 2) {
        printf("Хранится float: %.2f\n", td.data.float_value);
    } else if (td.type == 3) {
        printf("Хранится char: %c\n", td.data.char_value);
    }

    return 0;
}