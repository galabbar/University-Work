//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//myfunctions.h

#include <stdio.h>
#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

//Struct for user identification
typedef struct User_Input{

    char Name[30];
    int Age;
    float height;
    double weight;
    char gender;

}User_Input;

/* Function prototypes */
void CreateBinaryFile(char*);
void PrintBinaryFile(char*);
void PrintTextFile(char*);

#endif // MYFUNCTIONS_H_INCLUDED
