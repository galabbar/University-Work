//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//main.c

#include <stdio.h>
#include "myFunctions.h"


//Beginning of main
int main(){

    char *str1 = (char*)malloc(100 * sizeof(char)), *str2 = (char*)malloc(100 * sizeof(100));
    int radius;

    printf("string frequency function:\n\n");

    printf("Enter a string: ");
    gets(str2); puts("");

    printf("Enter another string: ");
    gets(str1); puts("");

    printf("The number of times %s appeared in %s is %d times.\n\n", str2, str1, strFrequency(str1, str2));


    printf("string concatination function:\n\n");

    printf("Enter a string: ");
    gets(str1); puts("");

    printf("Enter another string: ");
    gets(str2); puts("");

    printf("The two strings concatinated is: %s\n\n", strCat(str1, str2));

    printf("draw circle function:\n\n");

    printf("Enter a radius: ");
    scanf("%d", &radius);

    Circle(radius);

    return 0;
}
//End of main

//Compile command: gcc main.c -o main
//Run command: ./main
