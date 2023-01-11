//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Question3.c

#include <stdio.h>
#include <assert.h>

//Macro that checks if a character is lower case
#define islower(x) x >= 'a' && x <= 'z'

//Beginning of program
int main(){

    char c;
    printf("Enter a letter: ");
    scanf("%c", &c);

    assert(islower(c));

    return 0;
}
//End of program
