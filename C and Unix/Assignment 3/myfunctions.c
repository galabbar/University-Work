//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 3
//myfunctions.c

#include <stdio.h>
#include <string.h>
#include "myfunctions.h"

//prints all the strings entered from the user provided sentence in reverse order
void tokenizer(char str[]){

        char arrstr[100][100] = {0}; //Array of strings to store the strings
        int i = 0;

        //string stores the string right before the space or the ' ' character
        char* string = strtok(str," ");

        //Loops through the string and stores them all in the array of strings. The loop stops when string has reached '\0'
        while (string)
        {
            strcpy((arrstr + i), string); //stores the string into the array of strings in index i

            string = strtok(NULL, " "); //Removes the space and collects the string, and stores it in string

            i++; //i is incremented
        }

        //Prints the array of strings in reverse order
        for (i; i - 1 >= 0; i--)
            printf("%s   ", arrstr+(i - 1) );
}

//counts and returns the total occurances of a letter in a user provided sentence
int totalOcc(char str[],char ch){

        char *str2 = {0}; //String that stores the original string, but gets modified each iteration
        int count = 0; //Counter that counts occurences

        //strchr searches for the character ch and modifies the string to the character right in front of it
        str2 = strchr(str, ch);

        //iterates through str2 until it is NULL
        while(strchr(str2, ch))
        {
            strcpy(str2, strchr(str2, ch)); //str2 stores its modified self within str2

            str2 += 1; //str2's address is incremented so the str2 doesn't stay the same

            count += 1; //The counter is incremented each time ch occured
        }

        return count; //Returns count (the number of occurences
}

//Takes an array of strings and modifies it to become sorted using bubble sort
void sortedStrings(char str[][10], int size){

    int i,j;

    //increases i throughout the loop
    for (i = 0; i < size - 1; i++)

        //Goes through the array of strings while subtracting i in each new loop
        for (j = 0; j < size - (1 + i); j++)
        {
            //Compares the two strings using strcmp
            //If the current string is alphabetically inferior to the next string, then they switch places
            if (strcmp( str + j + 1, str + j) < 0 )
            {
                char temp[10] = {0}; //temporary string to store the next string

                strcpy( temp, (str + j + 1) ); //stores the next string into the temporary string

                strcpy( str + j + 1, str + j); //stores the current string into the next string

                strcpy( str + j, temp); //stores the temporary string (next string) into the current string
            }
        }

    //Now the array of strings should be alphabetically sorted
}
