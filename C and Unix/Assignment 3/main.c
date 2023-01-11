//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 3
//main.c

#include <stdio.h>
#include "myfunctions.h"

int main(){

    char str[] = {0}, c, arrStr[10][10] = {0};

    printf("Tokenizer function:\n\n");

    printf("Enter a sentence: ");
    gets(str);

    tokenizer(str);

    puts("\n\n");

    printf("totalOcc function:\n\n");

    printf("Enter a sentence: ");
    gets(str);
    printf("Enter a character: ");
    scanf("%c", &c);

    printf("The number of %c occurences in your sentence is: %d\n\n", c, totalOcc(str,c));

    puts("\n\n");

    printf("sortedStrings function:\n\n");

    int size, i;

    printf("Enter the size of your list: ");
    scanf("%d", &size);

    printf("Enter a list of names: \n");

    for (i = 0; i < size; i++)
        scanf("%s", arrStr + i);
    puts("\n"); //newline

    puts("The list you have entered is: \n");
    for (i = 0; i < size; i++)
        printf("%s  ", *(arrStr + i));
    puts("\n"); //newline

    sortedStrings(arrStr,size);

    puts("The list after it is sorted: \n");

    for (i = 0; i < size; i++)
        printf("%s  ", *(arrStr + i));


    return 0;
}

//Compile: gcc main.c -o main
//Run: ./main
