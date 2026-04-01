#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float average_grade;
};

int main() {

    struct Student s;

    strcpy(s.name, "Виктория");
    s.age = 17;
    s.average_grade = 5.0;


    printf("Имя: %s\n", s.name);
    printf("Возраст: %d\n", s.age);
    printf("Средний балл: %.2f\n\n", s.average_grade);

    printf("Введите имя: ");
    scanf("%49s", s.name);

    printf("Введите возраст: ");
    scanf("%d", &s.age);
    printf("Введите средний балл: ");
    scanf("%f", &s.average_grade);

    
    printf("Вы ввели:\n");
    printf("Имя: %s\n", s.name);
    printf("Возраст: %d\n", s.age);
    printf("Средний балл: %.2f\n", s.average_grade);

    return 0;
}