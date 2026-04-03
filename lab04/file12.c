#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void addPerson(const char *filename) {
    FILE *file = fopen(filename, "ab"); 
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }
    
    Person p;
    printf("\n Добавление нового человека\n");
    printf("Введите имя: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0'; 
    
    printf("Введите возраст: ");
    scanf("%d", &p.age);
    getchar();
    
    fwrite(&p, sizeof(Person), 1, file);
    fclose(file);
    
    printf(" Запись успешно добавлена!\n");
}

void viewAllPersons(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Файл базы данных не существует или пуст\n");
        printf("Сначала добавьте записи\n");
        return;
    }
    
    Person p;
    int count = 0;
    
    printf("\nСписок всех людей\n");
    printf("\n");
    
    while (fread(&p, sizeof(Person), 1, file) == 1) {
        count++;
        printf("%d. Имя: %s, Возраст: %d\n", count, p.name, p.age);
    }
    
    if (count == 0) {
        printf("База данных пуста.\n");
    } else {
        printf("\n");
        printf("Всего записей: %d\n", count);
    }
    
    fclose(file);
}

void findPerson(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Файл базы данных не существует!\n");
        return;
    }
    
    char search_name[50];
    printf("\nПоиск человека\n");
    printf("Введите имя для поиска: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    
    Person p;
    int found = 0;
    int record_num = 0;
    
    while (fread(&p, sizeof(Person), 1, file) == 1) {
        record_num++;
        if (strcmp(p.name, search_name) == 0) {
            printf("\nНайдено\n");
            printf("  Запись #%d\n", record_num);
            printf("  Имя: %s\n", p.name);
            printf("  Возраст: %d\n", p.age);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Человек с именем '%s' не найден\n", search_name);
    }
    
    fclose(file);
}

void deletePerson(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Файл базы данных не существует\n");
        return;
    }
    
    char search_name[50];
    printf("\nУдаление записи\n");
    printf("Введите имя человека для удаления: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    

    FILE *temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        printf("Ошибка создания временного файла\n");
        fclose(file);
        return;
    }
    
    Person p;
    int found = 0;
    int deleted_count = 0;
    
    while (fread(&p, sizeof(Person), 1, file) == 1) {
        if (strcmp(p.name, search_name) == 0) {
            found = 1;
            deleted_count++;
            printf(" Удалена запись: %s, %d лет\n", p.name, p.age);
        } else {
            fwrite(&p, sizeof(Person), 1, temp);
        }
    }
    
    fclose(file);
    fclose(temp);
    
    if (found) {

        remove(filename);
        rename("temp.bin", filename);
        printf("Удалено записей: %d\n", deleted_count);
    } else {
        remove("temp.bin");
        printf("Человек с именем '%s' не найден\n", search_name);
    }
}

void updateAge(const char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Файл базы данных не существует\n");
        return;
    }
    
    char search_name[50];
    printf("\nОбновление возраста\n");
    printf("Введите имя человека: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    
    Person p;
    int found = 0;
    long pos;
    
    while (fread(&p, sizeof(Person), 1, file) == 1) {
        if (strcmp(p.name, search_name) == 0) {
            found = 1;
            printf("Текущий возраст: %d\n", p.age);
            printf("Введите новый возраст: ");
            int new_age;
            scanf("%d", &new_age);
            getchar(); 
        
            fseek(file, -sizeof(Person), SEEK_CUR);
            
            p.age = new_age;
            
            fwrite(&p, sizeof(Person), 1, file);
            printf("Возраст успешно обновлен\n");
            break;
        }
    }
    
    if (!found) {
        printf("Человек с именем '%s' не найден\n", search_name);
    }
    
    fclose(file);
}

int getRecordCount(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return 0;
    }
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    
    return size / sizeof(Person);
}


void showMenu() {
    printf("\n\n");
    printf(" Файловая база данных 'люди'\n");
    printf("\n");
    printf("1. Добавить человека\n");
    printf("2. Показать всех людей\n");
    printf("3. Найти человека по имени\n");
    printf("4. Удалить человека по имени\n");
    printf("5. Обновить возраст\n");
    printf("6. Статистика базы данных\n");
    printf("0. Выход\n");
    printf("\n");
    printf("Выберите действие: ");
}

void showStatistics(const char *filename) {
    printf("\nСтатистика базы данных\n");
    
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("База данных пуста или не существует\n");
        return;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    int record_count = file_size / sizeof(Person);
    
    printf("Размер файла: %ld байт\n", file_size);
    printf("Количество записей: %d\n", record_count);
    printf("Размер одной записи: %zu байт\n", sizeof(Person));
    
    if (record_count > 0) {
        Person p;
        int total_age = 0;
        int min_age = 999, max_age = 0;
        char youngest[50], oldest[50];
        
        fseek(file, 0, SEEK_SET);
        
        for (int i = 0; i < record_count; i++) {
            fread(&p, sizeof(Person), 1, file);
            total_age += p.age;
            
            if (p.age < min_age) {
                min_age = p.age;
                strcpy(youngest, p.name);
            }
            if (p.age > max_age) {
                max_age = p.age;
                strcpy(oldest, p.name);
            }
        }
        
        printf("\nСредний возраст: %.2f лет\n", (float)total_age / record_count);
        printf("Самый молодой: %s (%d лет)\n", youngest, min_age);
        printf("Самый старший: %s (%d лет)\n", oldest, max_age);
    }
    
    fclose(file);
}

int main() {
    const char *filename = "people.dat";
    int choice;
    
    printf("Добро пожаловать в файловую базу данных\n");
    
    do {
        showMenu();
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                addPerson(filename);
                break;
            case 2:
                viewAllPersons(filename);
                break;
            case 3:
                findPerson(filename);
                break;
            case 4:
                deletePerson(filename);
                break;
            case 5:
                updateAge(filename);
                break;
            case 6:
                showStatistics(filename);
                break;
            case 0:
                printf("\nДо свидания!\n");
                break;
            default:
                printf("Неверный выбор! Попробуйте снова\n");
        }
    } while (choice != 0);
    
    return 0;
}