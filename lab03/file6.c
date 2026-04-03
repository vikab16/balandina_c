#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size) {
    if (size == 0) {
        printf("Массив пуст\n");
        return;
    }
    printf("Массив (%d элементов): ", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

int* insertElement(int *arr, int *size, int position, int value) {
    if (position < 0 || position > *size) {
        printf("Ошибка: позиция %d выходит за пределы [0, %d]\n", position, *size);
        return arr;
    }
    
    (*size)++;
 
    int *temp = (int*)realloc(arr, (*size) * sizeof(int));
    if (temp == NULL) {
        printf("Ошибка перевыделения памяти!\n");
        (*size)--;
        return arr;
    }
    arr = temp;
    
    for (int i = *size - 1; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = value;
    
    printf("Элемент %d вставлен в позицию %d\n", value, position);
    return arr;
}

int* insertAtBeginning(int *arr, int *size, int value) {
    return insertElement(arr, size, 0, value);
}

int* insertAtEnd(int *arr, int *size, int value) {
    return insertElement(arr, size, *size, value);
}

int* insertAfterValue(int *arr, int *size, int target, int value) {

    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Элемент %d не найден в массиве\n", target);
        return arr;
    }
    
    return insertElement(arr, size, index + 1, value);
}

int* insertBeforeValue(int *arr, int *size, int target, int value) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Элемент %d не найден в массиве\n", target);
        return arr;
    }
    
    return insertElement(arr, size, index, value);
}

int* insertMultiple(int *arr, int *size, int position, int *values, int count) {
    if (position < 0 || position > *size) {
        printf("Ошибка: неверная позиция для множественной вставки\n");
        return arr;
    }
    
    int oldSize = *size;
    *size += count;
    
    int *temp = (int*)realloc(arr, (*size) * sizeof(int));
    if (temp == NULL) {
        printf("Ошибка перевыделения памяти\n");
        *size = oldSize;
        return arr;
    }
    arr = temp;
    
    for (int i = oldSize - 1; i >= position; i--) {
        arr[i + count] = arr[i];
    }
    
 
    for (int i = 0; i < count; i++) {
        arr[position + i] = values[i];
    }
    
    printf("Вставлено %d элементов в позицию %d\n", count, position);
    return arr;
}

int main() {
    int *arr;
    int size, choice, position, value, target, count;
    
    printf("Введите начальный размер массива: ");
    scanf("%d", &size);
    
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    
    if (size > 0) {
        printf("Введите элементы массива:\n");
        inputArray(arr, size);
    }
    printArray(arr, size);
    
    do {
        printf("\nМеню вставки\n");
        printf("1. Вставить элемент в позицию\n");
        printf("2. Вставить элемент в начало\n");
        printf("3. Вставить элемент в конец\n");
        printf("4. Вставить после элемента по значению\n");
        printf("5. Вставить перед элементом по значению\n");
        printf("6. Вставить несколько элементов\n");
        printf("7. Вывести массив\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Введите позицию для вставки (0-%d): ", size);
                scanf("%d", &position);
                printf("Введите значение: ");
                scanf("%d", &value);
                arr = insertElement(arr, &size, position, value);
                printArray(arr, size);
                break;
                
            case 2:
                printf("Введите значение для вставки в начало: ");
                scanf("%d", &value);
                arr = insertAtBeginning(arr, &size, value);
                printArray(arr, size);
                break;
                
            case 3:
                printf("Введите значение для вставки в конец: ");
                scanf("%d", &value);
                arr = insertAtEnd(arr, &size, value);
                printArray(arr, size);
                break;
                
            case 4:
                printf("Введите целевое значение: ");
                scanf("%d", &target);
                printf("Введите значение для вставки: ");
                scanf("%d", &value);
                arr = insertAfterValue(arr, &size, target, value);
                printArray(arr, size);
                break;
                
            case 5:
                printf("Введите целевое значение: ");
                scanf("%d", &target);
                printf("Введите значение для вставки: ");
                scanf("%d", &value);
                arr = insertBeforeValue(arr, &size, target, value);
                printArray(arr, size);
                break;
                
            case 6:
                printf("Введите позицию для вставки (0-%d): ", size);
                scanf("%d", &position);
                printf("Сколько элементов вставить? ");
                scanf("%d", &count);
                
                int *values = (int*)malloc(count * sizeof(int));
                if (values == NULL) {
                    printf("Ошибка выделения памяти\n");
                    break;
                }
                
                printf("Введите %d элементов:\n", count);
                for (int i = 0; i < count; i++) {
                    printf("Значение %d: ", i + 1);
                    scanf("%d", &values[i]);
                }
                
                arr = insertMultiple(arr, &size, position, values, count);
                free(values);
                printArray(arr, size);
                break;
                
            case 7:
                printArray(arr, size);
                break;
                
            case 0:
                printf("Выход из программы\n");
                break;
                
            default:
                printf("Неверный выбор\n");
        }
    } while (choice != 0);
    
    free(arr);
    return 0;
}