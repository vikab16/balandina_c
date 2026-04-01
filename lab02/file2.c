#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    int age;
    float average_grade;
};

int main() {

    struct Student s[5];
    
    strcpy(s[0].name, "Вика");
    s[0].age = 17;
    s[0].average_grade = 5.0;
    
    strcpy(s[1].name, "Яна");
    s[1].age = 67;
    s[1].average_grade = 4.7;
    
    strcpy(s[2].name, "Даша");
    s[2].age = 26;
    s[2].average_grade = 4.5;

    strcpy(s[3].name, "Лизка");
    s[3].age = 21;
    s[3].average_grade = 5.0;
    
    strcpy(s[4].name, "Алинка");
    s[4].age = 19;
    s[4].average_grade = 4.2;
    
    printf("Список всех студентов\n");

    for (int i = 0; i < 5; i++) {
        printf("Студент %d:\n", i + 1);
        printf("  Имя: %s\n", s[i].name);
        printf("  Возраст: %d лет\n", s[i].age);
        printf("  Средний балл: %.2f\n\n", s[i].average_grade);
    }
    
    int max_index = 0;  

    for (int i = 1; i < 5; i++) {
        if (s[i].average_grade > s[max_index].average_grade) {
            max_index = i;
        }
    }

    printf("Студент с максимальным средним баллом\n");
    printf("Имя: %s\n", s[max_index].name);
    printf("Возраст: %d лет\n", s[max_index].age);
    printf("Средний балл: %.2f\n", s[max_index].average_grade);
    
    return 0;
}