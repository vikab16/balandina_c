#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size) {
    if (size == 0) {
        printf("Массив пуст\n");
        return;
    }
    printf("Массив %d элементов: ", size);
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

int* deleteElement(int *arr, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Ошибка: индекс %d выходит за пределы [0, %d]\n", index, *size - 1);
        return arr;
    }
    
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
    

    int *temp = (int*)realloc(arr, (*size) * sizeof(int));
    if (temp == NULL && *size > 0) {
        printf("Предупреждение: не удалось уменьшить память\n");
        return arr;
    }
    
    return temp;
}

int* deleteByValue(int *arr, int *size, int value) {
    int index = -1;
    
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Элемент со значением %d не найден\n", value);
        return arr;
    }
    
    printf("Найден элемент %d с индексом %d\n", value, index);
    return deleteElement(arr, size, index);
}

int* deleteAllByValue(int *arr, int *size, int value) {
    int count = 0;
    
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    
    if (count == 0) {
        printf("Элемент со значением %d не найден\n", value);
        return arr;
    }
    
    int newSize = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] != value) {
            arr[newSize++] = arr[i];
        }
    }
    
    *size = newSize;
    
    int *temp = (int*)realloc(arr, (*size) * sizeof(int));
    if (temp == NULL && *size > 0) {
        printf("Предупреждение: не удалось уменьшить память\n");
        return arr;
    }
    
    printf("Удалено %d элементов со значением %d\n", count, value);
    return temp;
}

int main() {
    int *arr;
    int size, choice, index, value;
    

    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    
    printf("Введите элементы массива:\n");
    inputArray(arr, size);
    printArray(arr, size);
    
    do {
        printf("\nМеню удаления\n");
        printf("1. Удалить элемент по индексу\n");
        printf("2. Удалить элемент по значению (первое вхождение)\n");
        printf("3. Удалить все элементы с заданным значением\n");
        printf("4. Вывести массив\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (size == 0) {
                    printf("Массив пуст, нечего удалять\n");
                    break;
                }
                printf("Введите индекс для удаления (0-%d): ", size - 1);
                scanf("%d", &index);
                arr = deleteElement(arr, &size, index);
                if (size > 0) {
                    printArray(arr, size);
                } else {
                    printf("Массив стал пустым\n");
                }
                break;
                
            case 2:
                if (size == 0) {
                    printf("Массив пуст, нечего удалять\n");
                    break;
                }
                printf("Введите значение для удаления: ");
                scanf("%d", &value);
                arr = deleteByValue(arr, &size, value);
                if (size > 0) {
                    printArray(arr, size);
                } else {
                    printf("Массив стал пустым\n");
                }
                break;
                
            case 3:
                if (size == 0) {
                    printf("Массив пуст, нечего удалять\n");
                    break;
                }
                printf("Введите значение для удаления всех вхождений: ");
                scanf("%d", &value);
                arr = deleteAllByValue(arr, &size, value);
                if (size > 0) {
                    printArray(arr, size);
                } else {
                    printf("Массив стал пустым\n");
                }
                break;
                
            case 4:
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