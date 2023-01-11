//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Lab 6
//PostLab6.2.c

#include <stdio.h>
#include <string.h>

//Beginning of main
int main()
{
    //strMain is user Input
    //str is to store strMain after it's changed using strtok
    //AreaCode is to store the area code string
    //Number is to store the number string
    char strMain[20] = {0}, str[20] = {0}, *AreaCode = {0}, *Number = {0};

    int AreaCodeInt; //to store AreaCode as an integer
    long NumberLong = 0; //to store Number as a long integer

    //User Input
    printf("Enter a number in the form of (xxx) xxx-xxxx: ");
    gets(strMain);

    strcpy(str,strMain);

    /*Multiple strtok's to change the string
     and convert AreaCode to an integer
     and Number into a long integer         */

    AreaCode = strtok(strtok(strMain, "("), ")");
    AreaCodeInt = atoi(AreaCode);

    strcpy(strMain,str);

    Number = strtok(strMain, " ");
    Number = strtok(NULL, " ");

    Number = strtok(Number,"-");

    NumberLong += atol(Number)*10000;

    Number = strtok(NULL, "-");

    NumberLong += atol(Number);

    /***************************************/

    printf("The number you entered is: (%d) %ld\n", AreaCodeInt, NumberLong);

    return 0;
}
//End of Main
