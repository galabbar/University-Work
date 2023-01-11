//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//myFunctions.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myFunctions.h"

//Draws a circle with radius r
void Circle(int r){

    int y = -r, x = -r;

    //draws a circle while y does not equal to r + 1
    while (y != r + 1){

        //if x^2 + y^2 are under r^2 + 1, print *
        if (x*x + y*y < r*r + 1 && x*x + y*y < r*r - 1)
            printf("*");

        //if not, print a space
        else
            printf(" ");

        //if x is equal to r + 1, then x is assigned to -r, y is incremented, a new line is printed, and the loop continues.
        if (x == r){

            x = -r;
            y++;
            puts("");

            continue;
        }

        x++; //x is incremented
    }
}

//Concatinates two strings into one, and returns it
char *strCat(char *str1, char *str2){

    //checks if str1 is null, str2 is null or both
    if (!*str1 || !*str2){

        //Returns str1 if str2 is null
        if (*str1 && !*str2)
            return str1;

        //returns str2 is str1 is null
        if (!*str1 && *str2)
            return str2;

        //returns null if both strings are null
        return NULL;
    }

    /*The case where both strings are not null*/

    //string declaration using malloc
    char *strResult = malloc(100 * sizeof(char));
    int i = 0, j = 0; //indexes for the string

    //loops through str1 until strResult is equal to it. The loop ends when str1 reaches null
    while (*(str1 + j)){

        *(strResult + i) = *(str1 + j);

        i++;
        j++;
    }

    j = 0;

    //loops through str2 until strResult is equal to str1 + str2. The loop ends when str2 reaches null
    while (*(str2 + j)){

        *(strResult + i) = *(str2 + j);

        i++;
        j++;
    }

    *(strResult + i) = '\0'; //assigns the last character of the string to the null character

    return strResult; //Returns the result string (concatinated strings)
}

//Counts how many occurances of str2 are in str1
int strFrequency(char *str1, char *str2){

    //count is the number of occurances
    //i and j are the indexes
    //isSame is a boolean value to check whether the str1 substring is equal to str2
    int count = 0, i = 0, j = 0, isSame = 0;

    //loops through str1 and counts how many occurances of str2 in str1. The loop ends str1 is null
    while (*(str1 + i) != '\0')
    {
        //if the first character in str1's substring is equal to the first character of str2
        if (*(str1 + i) == *(str2 + j)){

            //loops through str2 and checks whether str2 is equal to str1's substring
            while (*(str2 + j) != '\0'){

                //if str2's current character does not equal str1's current character
                if (*(str2 + j) != *(str1 + i))
                {
                    isSame = 0; //isSame is false
                    i--;        //sets back the index of str1 after going above the intended index

                    break; //breaks out of loop
                }

                //if str1 is null, then there are no more substrings to compare to.
                if (*(str1 + i) == '\0')
                {
                    isSame = 0; //isSame is switched to false
                    break; //breaks out of loop
                }

                isSame = 1; //isSame remains true since there is no loop that turned it false

                //Both indexes increment
                i++;
                j++;
            }
        }

        j = 0; //j is zero so the comparison starts anew

        //if isSame is true, then count is incremented, isSame is switched to false, and the loop is continued.
        if (isSame)
        {
            count++;
            isSame = 0;

            continue;
        }

        i++; //str1's index is incremented
    }

    return count; //returns count (The number of occurences)
}
