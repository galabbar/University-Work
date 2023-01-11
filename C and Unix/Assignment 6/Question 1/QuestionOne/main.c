//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//main.c

#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

//Beginning of program
int main(){

    int choiceNum;
    char choice;


    printf("Would you like to start? (y/n): ");
    scanf(" %c", &choice);

    //Main loop for the user to do what he pleases.
    while (choice != 'n' && choice != 'N'){

        printf("Your choices are:\n\n");
        printf("1.create binary file\n");
        printf("2.print binary file on screen\n");
        printf("3.print binary file contents on a text file\n");
        printf("4.exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choiceNum);

        if ( choiceNum == 1 ){

            char* fileName = (char*)malloc(20);

            printf("Enter your binary file name: ");
            scanf("%s", fileName);

            CreateBinaryFile(fileName);
        }

        else if ( choiceNum == 2 ){

            char* fileName = (char*)malloc(20);

            printf("Enter your binary file name: ");
            scanf("%s", fileName);

            PrintBinaryFile(fileName);
        }

        else if ( choiceNum == 3 ){

            char* fileName = (char*)malloc(20);

            printf("Enter your binary file name: ");
            scanf("%s", fileName);

            PrintTextFile(fileName);
        }

        else if ( choiceNum == 4 )
            break;

        else{

            printf("You did not enter one of the choices! Please select one of them.\n");
            continue;
        }

        printf("Would you like to continue? (y/n): ");
        scanf(" %c", &choice);

    }

    return 0;
}
//End of program
