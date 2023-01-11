//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//quiz.c

#include <stdio.h>
#include <string.h>

int main(){

    char arr_str[10][50] = {0};
    int i,j;

    printf("Enter ten strings: ");
    for (i = 0; i < 10; i++)
        scanf("%s",arr_str + i);

    printf("The strings you have entered: \n");
    for (i = 0; i < 10; i++)
        printf("%s  ",*(arr_str + i));
    puts("\n\n");

    for (i = 0; i < 9; i++)
    for (j = 0; j < 9 - i; j++){

        if ( strcmp( (arr_str + j + 1), (arr_str + j) ) < 0 ){

            char temp[50] = {0};

            strcpy(temp, (arr_str + j + 1));

            strcpy((arr_str + j + 1), (arr_str + j));

            strcpy((arr_str + j),temp);
        }
    }

    printf("The strings after being sorted: \n");
    for (i = 0; i < 5; i++)
        printf("%s  ",*(arr_str + i));

    return 0;
}
