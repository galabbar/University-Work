//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//main.c

#include <stdio.h>
#include "myFunction.c"

int main(){

    char* str1,*str2;

    //allocate 20 cells of memory for both str1 and str2 using malloc
    str1 = (char*)malloc(20 * sizeof(char));
    str2 = (char*)malloc(20 * sizeof(char));

    //user input for str1
    printf("Enter your first string: ");
    gets(str1);

    printf("\n");

    //user input for str2
    printf("Enter your second string: ");
    gets(str2);

    printf("\n\n");

    printf("%d\n", NumofModifications(str1,str2));

    return 0;
} //End of program

//Compile command: gcc main.c -o main
//run command: ./main
