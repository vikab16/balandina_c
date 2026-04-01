#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[50];
    struct Date birth;
};

int main() {
    struct Person person[3]; 
    strcpy(person[0].name, "Виктория Баландина");
    person[0].birth.day = 17;
    person[0].birth.month = 2;
    person[0].birth.year = 2009;

    strcpy(person[1].name, "Яна Гребенникова");
    person[1].birth.day = 6;  
    person[1].birth.month = 1;
    person[1].birth.year = 1938;

    strcpy(person[2].name, "Дон Дарья");
    person[2].birth.day = 9;  
    person[2].birth.month = 12;
    person[2].birth.year = 1999;

    printf("Все пользователи\n");

    for (int i = 0; i < 3; i++) {
        printf("Человек %d:\n", i + 1);
        printf("  Имя: %s\n", person[i].name);
        printf("  Дата рождения: %02d.%02d.%d\n\n",  
               person[i].birth.day,
               person[i].birth.month,
               person[i].birth.year);
    }

    printf("Люди, родившиеся после 2000 года\n");
    int found = 0;  

    for (int i = 0; i < 3; i++) {
        if (person[i].birth.year > 2000) { 
            printf("Имя: %s\n", person[i].name);
            printf("Дата рождения: %02d.%02d.%d\n\n",
                   person[i].birth.day,
                   person[i].birth.month,
                   person[i].birth.year);
            found = 1; 
        }
    }

    if (!found) {
        printf("Людей, родившихся после 2000 года, не найдено\n");
    }

    return 0;
}