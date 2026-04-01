#include <stdio.h>
#include <string.h>

enum Course {
    First,
    Second,
    Third,
    Fourth
};

struct Student {
    char name[50];
    int age;
    enum Course course;
    float average_grade;
};

#define MAX_STUDENTS 100

void addStudent(struct Student *students, int *count);
void printAllStudents(struct Student *students, int count);
void findStudentByName(struct Student *students, int count, char *search_name);
void sortByGrade(struct Student *students, int count);
const char* getCourseName(enum Course course);


int main() {
    struct Student students[MAX_STUDENTS];
    int student_count = 0;
    int choice;
    char search_name[50];

    printf("Система учёта студентов\n");

    do {
        printf("\nМеню:\n");
        printf("1. Добавить студента\n");
        printf("2. Вывести всех студентов\n");
        printf("3. Найти студента по имени\n");
        printf("4. Отсортировать по среднему баллу\n");
        printf("5. Выход\n");
        printf("Выберите действие (1-5): ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addStudent(students, &student_count);
                break;
            case 2:
                printAllStudents(students, student_count);
                break;
            case 3:
                printf("Введите имя для поиска: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = 0; 
                findStudentByName(students, student_count, search_name);
                break;
            case 4:
                sortByGrade(students, student_count);
                printf("Список отсортирован по среднему баллу\n");
                break;
            case 5:
                printf("До свидания\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(struct Student *students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Массив заполнен. Нельзя добавить больше студентов\n");
        return;
    }

    struct Student new_student;

    printf("Введите имя: ");
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0; 

    printf("Введите возраст: ");
    scanf("%d", &new_student.age);
    getchar();

    int course_num;
    do {
        printf("Введите курс (1-Первый, 2-Второй, 3-Третий, 4-Четвёртый): ");
        scanf("%d", &course_num);
        getchar();
        if (course_num < 1 || course_num > 4) {
            printf("Ошибка! Введите число от 1 до 4\n");
        }
    } while (course_num < 1 || course_num > 4);

    new_student.course = (enum Course)(course_num - 1);

    printf("Введите средний балл: ");
    scanf("%f", &new_student.average_grade);
    getchar();

    students[*count] = new_student;
    (*count)++;

    printf("Студент %s добавлен\n", new_student.name);
}

void printAllStudents(struct Student *students, int count) {
    if (count == 0) {
        printf("Список студентов пуст\n");
        return;
    }

    printf("\nСписок всех студентов\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Имя: %s, Возраст: %d, Курс: %s, Средний балл: %.2f\n",
               i + 1,
               students[i].name,
               students[i].age,
               getCourseName(students[i].course),
               students[i].average_grade);
    }
}

void findStudentByName(struct Student *students, int count, char *search_name) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("Найден студент:\n");
            printf("Имя: %s, Возраст: %d, Курс: %s, Средний балл: %.2f\n",
                   students[i].name,
                   students[i].age,
                   getCourseName(students[i].course),
                   students[i].average_grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Студент с именем '%s' не найден\n", search_name);
    }
}

void sortByGrade(struct Student *students, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average_grade < students[j + 1].average_grade) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

const char* getCourseName(enum Course course) {
    switch (course) {
        case First:   return "Первый";
        case Second:  return "Второй";
        case Third:   return "Третий";
        case Fourth:  return "Четвёртый";
        default:     return "Неизвестный";
    }
}