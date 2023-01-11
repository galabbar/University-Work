//Name: Ghazi Najeeb Al-Abbar
//id: 2181148914
//PostLab8.c

#include <stdio.h>

typedef struct point{

    double x;
    double y;

}Point;

typedef struct rect{

    Point upperRight;
    Point lowerLeft;

}Rect;

double RECTarea(Rect rectangle){

    double width = rectangle.upperRight.x - rectangle.lowerLeft.x;
    double height = rectangle.upperRight.y - rectangle.lowerLeft.y;

    return width * height;
}

int main(){

    Rect rectangle;

    printf("Enter the lower left points of your rectangle in the form of (x,y): ");
    scanf("%lf %lf", &rectangle.lowerLeft.x, &rectangle.lowerLeft.y);

    printf("Enter the upper right points of your rectangle in the form of (x,y): ");
    scanf("%lf %lf", &rectangle.upperRight.x, &rectangle.upperRight.y);

    puts("\n");

    printf("The area of your rectangle is: %lf\n", RECTarea(rectangle));

    return 0;
}
