#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    const char *filename = "test.txt";
    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка: не удалось создать файл\n");
        return 1;
    }
    
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a test file.\n");
    fprintf(file, "We will calculate its size.\n");
    
    fclose(file);
    
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл '%s'\n", filename);
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    
    long file_size = ftell(file);

    printf("Файл: %s\n", filename);
    printf("Размер файла: %ld байт\n", file_size);
    
    fseek(file, 0, SEEK_SET);
    printf("Указатель возвращен в начало файла\n");
    
    fclose(file);
    
    return 0;
}