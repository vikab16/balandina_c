#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    file = fopen("test.txt", "w");
    if (file == NULL) {
        printf("Ошибка создания файла!\n");
        return 1;
    }
    
    fprintf(file, "Строка 1\n");
    fprintf(file, "Строка 2\n");
    fprintf(file, "Строка 3\n");
    fclose(file);
    
    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл\n");
        return 1;
    }
    
    char buffer[256];
    int ch;
    int line_count = 0;
    
    printf("Чтение файла с проверкой конца и ошибок:\n");
    printf("\n");
    
    while (1) {
        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            line_count++;
            printf("Прочитано: %s", buffer);
        } else {
            break;
        }
    }
    
  
    if (feof(file)) {
        printf("\n\n Достигнут конец файла (feof)\n");
        printf("  Всего прочитано строк: %d\n", line_count);
    }
    
    if (ferror(file)) {
        printf("\n Произошла ошибка при чтении файла (ferror)\n");
    } else {
        printf("Ошибок при чтении не обнаружено\n");
    }
    
    fclose(file);
    
    return 0;
}