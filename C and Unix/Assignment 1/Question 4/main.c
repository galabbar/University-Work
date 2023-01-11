//main.c

#include <stdio.h>
#include "myfunctions.h"

//Start of program
int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printStrings(num);

    printf("\n\n");

    return 0;
}//End of program

