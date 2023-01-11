#include <stdio.h>

//counts how many space characters in the string
int Countspace (char *str){

    //stops recurring when the character is a null character
    if (*str == '\0')
        return 0;

    //adds 1 to the recursion whenever a space character appears in the string
    if (*str == ' ')
        return 1 + Countspace(str + 1);

    //continues with the recursion whenever the two conditions above are not satisfied
    Countspace(str + 1);
}

//beginning of program
int main()
{
    char str[20]; //character array (string) is initialized to only have 20 elements

    printf("Enter a string (Must not exceed 20 characters): ");
    gets(str); //stores the string (input) inside the character array

    printf("The number of spaces in your string is: %d", Countspace(str));

    return 0;
}
//Ending of program
