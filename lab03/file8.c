#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int cap;
} List;

void add(List *l) {
    int v;
    printf("Значение: ");
    scanf("%d", &v);
    if (l->size >= l->cap) {
        l->cap = l->cap ? l->cap * 2 : 4;
        l->data = realloc(l->data, l->cap * sizeof(int));
    }
    l->data[l->size++] = v;
    printf("Добавлено\n");
}

void del(List *l) {
    if (!l->size) { printf("Пусто\n"); return; }
    int i;
    printf("Индекс (0-%d): ", l->size-1);
    scanf("%d", &i);
    if (i < 0 || i >= l->size) { printf(" Ошибка\n"); return; }
    for (int j = i; j < l->size-1; j++) l->data[j] = l->data[j+1];
    l->size--;
    if (l->size && l->size <= l->cap/3 && l->cap > 4) {
        l->cap /= 2;
        l->data = realloc(l->data, l->cap * sizeof(int));
    }
    printf("Удалено\n");
}

void print(List *l) {
    printf("\nСписок [%d/%d]: ", l->size, l->cap);
    if (!l->size) printf("пуст");
    else for (int i = 0; i < l->size; i++) printf("%d ", l->data[i]);
    printf("\n");
}

void resize(List *l) {
    int new;
    printf("Новая емкость (мин %d): ", l->size);
    scanf("%d", &new);
    if (new < l->size) { printf(" Слишком мало\n"); return; }
    l->data = realloc(l->data, new * sizeof(int));
    l->cap = new;
    printf("Емкость: %d\n", l->cap);
}

int main() {
    List list = {NULL, 0, 0};

    const char *menu[] = {
        "1. Добавить",
        "2. Удалить", 
        "3. Вывести",
        "4. Изменить размер",
        "0. Выход"
    };
    
    void (*actions[])(List*) = {add, del, print, resize};
    int choice;
    
    do {
        printf("\nМЕНЮ\n");
        for (int i = 0; i < 5; i++) printf("%s\n", menu[i]);
        printf("Выбор: ");
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 4) {
            actions[choice-1](&list);
        } else if (choice != 0) {
            printf(" Ошибка выбора\n");
        }
    } while (choice != 0);
    
    free(list.data);
    printf("До свидания\n");
    return 0;
}