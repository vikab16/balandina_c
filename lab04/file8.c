#include <stdio.h>
#include <string.h>


typedef struct {
    char name[50];  
    int age;       
} Person;

int main() {
    FILE *file;
    
    Person people[] = {
        {"Вика Баландина", 76},
        {"Яна Гребенникова", 67},
        {"Дон Дарья", 35},
        {"Леонова Елизавета", 28},
        {"Флоридова Алина", 35}
    };
    
    int size = sizeof(people) / sizeof(people[0]); 
    
    printf("Исходный массив структур:\n");
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d. Имя: %s, Возраст: %d\n", i + 1, people[i].name, people[i].age);
    }
    printf("\n");
    
    file = fopen("people_array.bin", "wb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для записи\n");
        return 1;
    }

    size_t elements_written = fwrite(people, sizeof(Person), size, file);
    
    if (elements_written != size) {
        printf("Ошибка: записано только %zu элементов из %d\n", elements_written, size);
        fclose(file);
        return 1;
    }
    
    printf("Массив структур успешно записан в файл 'people_array.bin'\n");
    printf("Записано %d структур, размером %zu байт = %zu байт\n\n", 
           size, sizeof(Person), size * sizeof(Person));
    
    fclose(file);

    file = fopen("people_array.bin", "rb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для чтения\n");
        return 1;
    }
    
    Person read_people[size]; 
    
    size_t elements_read = fread(read_people, sizeof(Person), size, file);
    
    if (elements_read != size) {
        printf("Ошибка: прочитано только %zu элементов из %d\n", elements_read, size);
        fclose(file);
        return 1;
    }
    
    printf("Массив структур успешно прочитан из файла\n");
    printf("Прочитано %zu структур\n\n", elements_read);
    
    fclose(file);

    printf("Прочитанный массив структур:\n");
    printf("\n");
    for (int i = 0; i < elements_read; i++) {
        printf("%d. Имя: %s, Возраст: %d\n", i + 1, read_people[i].name, read_people[i].age);
    }
    
    return 0;
}