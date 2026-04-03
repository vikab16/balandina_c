#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для записи\n");
        return 1;
    }
    
    printf("Запись форматированных данных в файл...\n");

    fprintf(file, "Имя: %s, Возраст: %d, Рост: %.2f\n", "Вика", 25, 165.5);
    fprintf(file, "Имя: %s, Возраст: %d, Рост: %.2f\n", "Яна", 30, 180.0);
    fprintf(file, "Имя: %s, Возраст: %d, Рост: %.2f\n", "Лиза", 22, 170.8);
    
    fprintf(file, "\nТаблица оценок\n");
    fprintf(file, "%-10s %-10s %-10s\n", "Студент", "Предмет", "Оценка");
    fprintf(file, "%-10s %-10s %-10d\n", "Баландина", "Математика", 5);
    fprintf(file, "%-10s %-10s %-10d\n", "Гребенниеова", "Физика", 4);
    fprintf(file, "%-10s %-10s %-10d\n", "Дон", "Информатика", 5);
    
    int a = 10, b = 20;
    float pi = 3.14159;
    char text[] = "Hello";
    
    fprintf(file, "\nРазные данные: %d + %d = %d\n", a, b, a + b);
    fprintf(file, "Число Пи: %.4f\n", pi);
    fprintf(file, "Текст: %s\n", text);
    
    fclose(file);
    printf("Данные успешно записаны\n\n");
    
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для чтения\n");
        return 1;
    }
    
    printf("Чтение данных из файла:\n");
    printf("\n");
    
    char name[50];
    int age;
    float height;
    
    printf("Персональные данные:\n");
    for (int i = 0; i < 3; i++) {
        if (fscanf(file, "Имя: %s, Возраст: %d, Рост: %f\n", name, &age, &height) == 3) {
            printf("  %d) Имя: %s, Возраст: %d, Рост: %.1f\n", i + 1, name, age, height);
        }
    }
    
    char student[20], subject[20];
    int grade;
    
    printf("\nТаблица оценок:\n");
    fscanf(file, "\n--- Таблица оценок ---\n");
    fscanf(file, "%*s %*s %*s\n"); 
    
    for (int i = 0; i < 3; i++) {
        fscanf(file, "%s %s %d\n", student, subject, &grade);
        printf("  %s: %s - %d\n", student, subject, grade);
    }
    
    int x, y, sum;
    float pi_value;
    char word[20];
    
    fscanf(file, "\nРазные данные: %d + %d = %d\n", &x, &y, &sum);
    fscanf(file, "Число Пи: %f\n", &pi_value);
    fscanf(file, "Текст: %s\n", word);
    
    printf("\nВычисленные данные:\n");
    printf("  %d + %d = %d\n", x, y, sum);
    printf("  Число Пи: %.4f\n", pi_value);
    printf("  Текст: %s\n", word);
    
    printf("\n");
    
    fclose(file);
    
    return 0;
}