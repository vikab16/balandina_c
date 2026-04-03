#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50]; 
    int age;        
} Student;

void inputStudent(Student *s, int index) {
    printf("\nСтудент %d:\n", index + 1);
    printf("  Имя: ");
    scanf(" %[^\n]", s->name);  
    printf("  Возраст: ");
    scanf("%d", &s->age);
}


void printStudent(Student *s, int index) {
    printf("%d. %s, %d лет\n", index + 1, s->name, s->age);
}

void printAllStudents(Student *students, int count) {
    if (count == 0) {
        printf("Список студентов пуст\n");
        return;
    }
    
    printf("\nСписок студентов\n");
    for (int i = 0; i < count; i++) {
        printStudent(&students[i], i);
    }
    printf("\n");
}

int findOldestStudent(Student *students, int count) {
    if (count == 0) {
        return -1;
    }
    
    int oldestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].age > students[oldestIndex].age) {
            oldestIndex = i;
        }
    }
    return oldestIndex;
}

int main() {
    Student *students;
    int n, i;
    int oldestIndex;
    
    printf("Введите количество студентов: ");
    scanf("%d", &n);
    
    students = (Student*)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    
    printf("\nЗаполнение данных\n");
    for (i = 0; i < n; i++) {
        inputStudent(&students[i], i);
    }
    
    printAllStudents(students, n);

    oldestIndex = findOldestStudent(students, n);
    
    if (oldestIndex != -1) {
        printf("\nСамый старший студент\n");
        printf("Имя: %s\n", students[oldestIndex].name);
        printf("Возраст: %d лет\n", students[oldestIndex].age);
        printf("Позиция в списке: %d\n", oldestIndex + 1);
    }
    
    free(students);
    
    return 0;
}