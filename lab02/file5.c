#include <stdio.h>
#include <string.h>  


enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Schedule {
    char subject[30]; 
    enum Day day;    
};

int main() {
    enum Day today = Wednesday;

    printf("Сегодня: ");
    switch (today) {
        case Monday:
            printf("Понедельник\n");
            break;
        case Tuesday:
            printf("Вторник\n");
            break;
        case Wednesday:
            printf("Среда\n");
            break;
        case Thursday:
            printf("Четверг\n");
            break;
        case Friday:
            printf("Пятница\n");
            break;
        case Saturday:
            printf("Суббота\n");
            break;
        case Sunday:
            printf("Воскресенье\n");
            break;
    }
    struct Schedule lesson;
    strcpy(lesson.subject, "Математика");  
    lesson.day = Friday;  

    printf("\nРасписание:\n");
    printf("Предмет: %s\n", lesson.subject);

    printf("День: ");
    switch (lesson.day) {
        case Monday:
            printf("Понедельник\n");
            break;
        case Tuesday:
            printf("Вторник\n");
            break;
        case Wednesday:
            printf("Среда\n");
            break;
        case Thursday:
            printf("Четверг\n");
            break;
        case Friday:
            printf("Пятница\n");
            break;
        case Saturday:
            printf("Суббота\n");
            break;
        case Sunday:
            printf("Воскресенье\n");
            break;
    }

    return 0;
}

