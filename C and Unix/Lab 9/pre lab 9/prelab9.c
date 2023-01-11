//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//prelab.c

#include <stdio.h>
#include <math.h>

enum Shape {square, rectangle, trapezoid, parallelogram};

typedef struct Rect {

    float length, width;

 } rect;

typedef struct Trap {

    float top, bottom, height;

 }trap;

typedef struct Para {

    float top2, side3;
    short obtuseAngle;

 }para;

typedef struct Dim {

    enum Shape whatshape;
    union parts {

        float forsqr;
        rect forrect;
        trap fortrap;
        para forparallel;

    }shapeparts;

    float area;
 }dimensions;


 int main(){

    dimensions arr[4] = {0};

    arr[0].whatshape = square;
    printf("Enter the width of the square's side: ");
    scanf("%f", &arr[0].shapeparts.forsqr);
    arr[0].area = arr[0].shapeparts.forsqr *arr[0].shapeparts.forsqr;
    printf("\n\n");

    arr[1].whatshape = rectangle;
    printf("Enter the components for the rectangle:\n");
    printf("Width: "); scanf("%f", &arr[1].shapeparts.forrect.width);
    printf("Length: "); scanf("%f", &arr[1].shapeparts.forrect.length);
    arr[1].area = arr[1].shapeparts.forrect.width * arr[1].shapeparts.forrect.length;
    printf("\n\n");

    arr[2].whatshape = trapezoid;
    printf("Enter the components for the trapezoid:\n");
    printf("Top: "); scanf("%f", &arr[2].shapeparts.fortrap.top);
    printf("Bottom: "); scanf("%f", &arr[2].shapeparts.fortrap.bottom);
    printf("Height: "); scanf("%f", &arr[2].shapeparts.fortrap.height);
    arr[2].area = ((arr[2].shapeparts.fortrap.top + arr[2].shapeparts.fortrap.bottom) / 2) * arr[2].shapeparts.fortrap.height;
    printf("\n\n");

    arr[3].whatshape = parallelogram;
    printf("Enter the components for the parallelogram:\n");
    printf("Top: "); scanf("%f", &arr[3].shapeparts.forparallel.top2);
    printf("side: "); scanf("%f", &arr[3].shapeparts.forparallel.side3);
    printf("Angle: "); scanf("%i", &arr[3].shapeparts.forparallel.obtuseAngle);
    arr[3].area = arr[3].shapeparts.forparallel.top2 * arr[3].shapeparts.forparallel.side3 * sin(arr[3].shapeparts.forparallel.obtuseAngle);
    printf("\n\n");

    int choice;

    printf("Enter any of the following to see the area of the shape that you have provided the input for:\n");
    printf("1. Square\n");
    printf("2. Rectangle\n");
    printf("3. Trapezoid\n");
    printf("4. Parallelogram\n");
    printf("5. Quit\n");
    printf("Provide your input: "); scanf("%d", &choice);
    choice--;
    printf("\n\n");

    while (choice != 4){

        if (choice == square)
            printf("The area of your square is: %f\n", arr[0].area);
        if (choice == rectangle)
            printf("The area of your rectangle is: %f\n", arr[1].area);
        if (choice == trapezoid)
            printf("The area of your trapezoid is: %f\n", arr[2].area);
        if (choice == parallelogram)
            printf("The area of your parallelogram is: %f\n", arr[3].area);
        printf("\n");

        printf("Enter any of the following to see the area of the shape that you have provided the input for:\n");
        printf("1. Square\n");
        printf("2. Rectangle\n");
        printf("3. Trapezoid\n");
        printf("4. Parallelogram\n");
        printf("5. Quit\n");
        printf("Provide your input: "); scanf("%d", &choice);
        choice--;
        printf("\n\n");
    }

    return 0;
 }
