//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//myfunctions.c

#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

//Creates a binary file and allows the user to enter his personal data
void CreateBinaryFile(char* fileName){

    //File declaration and opening for writing a binary file
    FILE* file = fopen(fileName, "wb");
    User_Input UI; //Struct User_Input object for the user to enter his data
    char choice; //character variable for the user to continue or stop as they wish

    //compulsory check to see if the file exists or is open. It exits the function otherwise
    if (!file){

        printf("The file does not exist / is not open!\n");
        return;
    }

    //prompts the user to enter his data. Offers to stop after each data entry cycle
    do{
        puts("");
        printf("Please enter your gender (m/M for male, f/F for female): ");
        scanf(" %c",&UI.gender);

        printf("Enter your name: ");
        scanf("%s", UI.Name);

        printf("Enter your age: ");
        scanf("%d", &UI.Age);

        printf("Enter your height in cm: ");
        scanf("%f", &UI.height);

        printf("Enter your weight in kg: ");
        scanf("%lf", &UI.weight);

        fwrite(&UI, sizeof(User_Input), 1, file);

        printf("Would you like to add another person? (Y/N): ");
        scanf(" %c", &choice);

    }while(choice != 'n' && choice != 'N');

    fclose(file); //file is closed after it's used

}

//Print the contents of a binary file on the screen
void PrintBinaryFile(char* fileName){

    //File declaration and opening for reading a binary file
    FILE* file = fopen(fileName, "rb");
    User_Input UI; //Struct User_Input object for the user to enter his data
    int i = 0;

    //compulsory check to see if the file exists or is open. It exits the function otherwise
    if (!file){

        printf("The file does not exist / is not open!\n");
        return;
    }

    //loops through the binary file and prints its contents on the screen
    while (1){

        fread(&UI, sizeof(User_Input), 1, file);
        if (feof(file)) break;

        printf("\nPerson #%d\n", ++i);
        printf("Name: %s\n", UI.Name);
        printf("Gender: %c\n", UI.gender);
        printf("Age: %d\n", UI.Age);
        printf("Height: %f\n", UI.height);
        printf("Weight: %lf\n", UI.weight);
        printf("\n\n");
    }

    fclose(file); //file is closed after it's used
}

//prints a binary file's contents on a text file
void PrintTextFile(char* fileName){

    //File declaration and opening for reading a binary file
    FILE* file = fopen(fileName, "rb");
    User_Input UI; //Struct User_Input object for the user to enter his data
    int i = 0;

    //Prompts the user to enter a text file name
    char* textfileName = (char*)malloc(20);
    printf("Enter the name of your text file: ");
    scanf("%s", textfileName);

    //File declaration and opening for writing on a text file
    FILE* F = fopen(textfileName, "w");

    //compulsory check to see if the file exists or is open. It exits the function otherwise
    if (!file){

        printf("The file does not exist / is not open!\n");
        return;
    }

    //compulsory check to see if the file exists or is open. It exits the function otherwise
    if (!F){

        printf("The file does not exist / is not open!\n");
        return;
    }


    //Goes through the binary file and prints its contents in a text file
    while (1){

        fread(&UI, sizeof(User_Input), 1, file);
        if (feof(file)) break;

        fprintf(F,"Person #%d\n", ++i);
        fprintf(F,"Name: %s\n", UI.Name);
        fprintf(F,"Gender: %c\n", UI.gender);
        fprintf(F,"Age: %d\n", UI.Age);
        fprintf(F,"Height: %f\n", UI.height);
        fprintf(F,"Weight: %lf\n", UI.weight);
        fprintf(F,"\n\n");
    }

    fclose(file); //file is closed after it's used
    fclose(F); //file is closed after it's used

    printf("Successfully printed on the text file!\n");
}
