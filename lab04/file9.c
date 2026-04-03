#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    
    file = fopen("test.txt", "w");
    if (file == NULL) {
        printf("Ошибка создания файла!\n");
        return 1;
    }
    
    fprintf(file, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    fprintf(file, "abcdefghijklmnopqrstuvwxyz\n");
    fclose(file);
    
    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    
    int ch;
    long position;
    

    printf("1. Чтение с 5-й позиции от начала файла:\n");
    fseek(file, 5, SEEK_SET); 
    position = ftell(file);
    printf("   Текущая позиция: %ld\n", position);
    ch = fgetc(file);
    printf("   Прочитанный символ: '%c' (код %d)\n\n", ch, ch);
    
    printf("2. Перемещение от текущей позиции:\n");
    printf("   Текущая позиция: %ld\n", ftell(file));
    fseek(file, 3, SEEK_CUR);  
    printf("   После fseek(file, 3, SEEK_CUR): %ld\n", ftell(file));
    ch = fgetc(file);
    printf("   Прочитанный символ: '%c'\n\n", ch);
  
    printf("3. Чтение с конца файла:\n");
    fseek(file, -5, SEEK_END);  
    position = ftell(file);
    printf("   Позиция за 5 символов до конца: %ld\n", position);
    ch = fgetc(file);
    printf("   Прочитанный символ: '%c'\n\n", ch);
    
    printf("4. Чтение строки с позиции 10:\n");
    fseek(file, 10, SEEK_SET);
    char buffer[50];
    fgets(buffer, sizeof(buffer), file);
    printf("   Прочитано: %s\n", buffer);
    
    fclose(file);
    
    return 0;
}