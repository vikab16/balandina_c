#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char buffer[256];

    printf("Введите строку текста: ");
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Ошибка при вводе строки\n");
        return 1;
    }
    
    buffer[strcspn(buffer, "\n")] = '\0';
    
    file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для записи\n");
        return 1;
    }
    
    fprintf(file, "%s\n", buffer);
    fclose(file);
    printf("Строка успешно записана в файл 'input.txt'\n\n");
    
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для чтения\n");
        return 1;
    }
    
    printf("Содержимое файла:\n");
    printf("\n");
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    printf("\n\n");
    fclose(file);
    
    return 0;
}