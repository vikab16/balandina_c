#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;

    file = fopen("strings.txt", "w");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для записи\n");
        return 1;
    }
    
    printf("Запись строк в файл...\n");
    
    fputs("Первая строка текста\n", file);
    fputs("Вторая строка с числами: 12345\n", file);
    fputs("Третья строка: Hello World!\n", file);
    fputs("Четвертая строка - последняя\n", file);
    
    char name[] = "Вика";
    char city[] = "Сириус";
    
    fputs("Имя: ", file);
    fputs(name, file);
    fputs("\nГород: ", file);
    fputs(city, file);
    fputs("\n", file);
    
    fclose(file);
    printf("Строки успешно записаны в файл\n\n");
    
    file = fopen("strings.txt", "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для чтения\n");
        return 1;
    }
    
    printf("Чтение строк из файла:\n");
    printf("\n");
    
    char buffer[256];
    int line_number = 1;
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("%d. %s\n", line_number++, buffer);
    }
    
    printf("\n");
    
    fclose(file);
    
    return 0;
}