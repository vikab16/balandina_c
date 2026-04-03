#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    file = fopen("test.txt", "w");
    
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл 'test.txt'\n");
        return 1; 
    }
    
    printf("Файл 'test.txt' успешно открыт для записи\n");
    
    fprintf(file, "Пример текста для записи в файл\n");
    
    fclose(file);
    printf("Файл 'test.txt' закрыт\n");
    
    return 0;
}