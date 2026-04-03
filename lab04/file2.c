#include <stdio.h>
#include <stdlib.h>

void writeToFile() {
    FILE *file = fopen("test.txt", "w");
    if (file == NULL) {
        perror("Ошибка при открытии файла для записи");
        exit(1);
    }
    
    // Запись символов
    putc('A', file);
    putc('B', file);
    putc('C', file);
    putc('\n', file);
    putc('1', file);
    putc('2', file);
    putc('3', file);
    putc('\n', file);
    
    fclose(file);
    printf("Данные записаны\n");
}

void readFromFile() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла для чтения");
        exit(1);
    }
    
    int ch;
    printf("Содержимое файла:\n");
    while ((ch = getc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
}

int main() {
    writeToFile();  
    readFromFile(); 
    return 0;
}