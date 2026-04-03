#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50]; 
    int age;        
} Person;

int main() {
    FILE *file;

    Person person1;
    
    strcpy(person1.name, "Вика Баландина");
    person1.age = 25;
    
    printf("Исходные данные:\n");
    printf("  Имя: %s\n", person1.name);
    printf("  Возраст: %d\n\n", person1.age);
    
    file = fopen("person.bin", "wb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для записи\n");
        return 1;
    }
    
    size_t elements_written = fwrite(&person1, sizeof(Person), 1, file);
    
    if (elements_written != 1) {
        printf("Ошибка: структура не была записана\n");
        fclose(file);
        return 1;
    }
    
    printf("Структура успешно записана в файл 'person.bin'\n");
    printf("Записано %zu байт\n\n", sizeof(Person));
    
    fclose(file);
    
    file = fopen("person.bin", "rb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для чтения\n");
        return 1;
    }
    
    Person person2;
    
    size_t elements_read = fread(&person2, sizeof(Person), 1, file);
    
    if (elements_read != 1) {
        printf("Ошибка: не удалось прочитать структуру\n");
        fclose(file);
        return 1;
    }
    
    printf("Структура успешно прочитана из файла\n");
    
    printf("\nПрочитанные данные:\n");
    printf("  Имя: %s\n", person2.name);
    printf("  Возраст: %d\n", person2.age);
    
    fclose(file);
    
    return 0;
}