//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Lab 6
//postLab6.1.c

#include <stdio.h>
#include <string.h>

//Beginning of main
int main()
{
    //strMain is the user input
    //strResult is to store the expanding string
    char strMain[20] = {0}, strResult[20] = {0};
    int i;

    //User input
    printf("Enter a string (Maximum length is 20 characters): ");
    gets(strMain);

    puts("\n");

    //Prints the string from length = 1 to length = string length
    for (i = strlen(strMain) - 1; i >= 0; i--)
    {
        strncpy(strResult, strMain, strlen(strMain) - i);

        puts(strResult);
    }

    return 0;
}
//End of main
