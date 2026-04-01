#include <stdio.h>

struct Rectangle {
    float width;   
    float height;  
};


float calculateAreaByValue(struct Rectangle rect) {
    return rect.width * rect.height;
}

float calculatePerimeterByValue(struct Rectangle rect) {
    return 2 * (rect.width + rect.height);
}

float calculateAreaByPointer(struct Rectangle *rect) {
    return rect->width * rect->height;
}

float calculatePerimeterByPointer(struct Rectangle *rect) {
    return 2 * (rect->width + rect->height);
}

int main() { 
    struct Rectangle Rect;

    Rect.width = 5.0;
    Rect.height = 3.0;

    printf("прямоугольник\n");
    printf("Ширина: %.2f\n", Rect.width);
    printf("Высота: %.2f\n\n", Rect.height);

    printf("по значению\n");
    printf("Площадь: %.2f\n", calculateAreaByValue(Rect));
    printf("Периметр: %.2f\n\n", calculatePerimeterByValue(Rect));

    printf("по указателю\n");
    printf("Площадь: %.2f\n", calculateAreaByPointer(&Rect));
    printf("Периметр: %.2f\n", calculatePerimeterByPointer(&Rect));

    return 0; 
}