#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Исходный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
    
    file = fopen("data.bin", "wb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для записи\n");
        return 1;
    }
    
    size_t elements_written = fwrite(numbers, sizeof(int), size, file);
    
    if (elements_written != size) {
        printf("Ошибка: записано только %zu элементов из %d\n", elements_written, size);
        fclose(file);
        return 1;
    }
    
    printf("Массив успешно записан в бинарный файл 'data.bin'\n");
    printf("Записано %zu элементов по %zu байт = %zu байт\n\n", 
           elements_written, sizeof(int), elements_written * sizeof(int));
    
    fclose(file);
    
    file = fopen("data.bin", "rb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл для чтения\n");
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    int num_elements = file_size / sizeof(int);
    
    int *read_numbers = (int*)malloc(file_size);
    if (read_numbers == NULL) {
        printf("Ошибка: не удалось выделить память\n");
        fclose(file);
        return 1;
    }
    
    size_t elements_read = fread(read_numbers, sizeof(int), num_elements, file);
    
    if (elements_read != num_elements) {
        printf("Ошибка: прочитано только %zu элементов из %d\n", elements_read, num_elements);
        free(read_numbers);
        fclose(file);
        return 1;
    }
    
    printf("Данные успешно прочитаны из бинарного файла\n");
    printf("Прочитано %zu элементов\n\n", elements_read);

    printf("Считанный массив:\n");
    for (int i = 0; i < elements_read; i++) {
        printf("%d ", read_numbers[i]);
    }
    printf("\n");
    
    free(read_numbers);
    fclose(file);
    
    return 0;
}