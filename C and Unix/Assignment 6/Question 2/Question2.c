//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Question2.c

#include <stdio.h>

//Macro that checks if a character is an alphabet
#define isalpha(x) (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')

//Macro that checks if a character is a digit
#define isdigit(x) x >= '0' && x <= '9'

//Macro that checks if the character is a control character
#define isctrl(x) x == 0 || (x >= 7 && x <= 13)

//Macro that checks if a character is a lower case letter
#define islower(x) x >= 'a' && x <= 'z'

//Macro that checks if a letter is an upper case letter
#define isupper(x) x >= 'A' && x <= 'Z'

//Prints true or false depending on the condition
void TorF(int Cond){

    if (Cond)
        printf("true\n");
    else
        printf("false\n");
}

//Beginning of program
int main(){

    printf("Is %c an alphabet? The answer is: ", 'a');
    TorF(isalpha('a'));

    printf("Is %c an alphabet? The answer is: ", 'A');
    TorF(isalpha('A'));

    printf("Is %c an alphabet? The answer is: ", ']');
    TorF(isalpha(']'));

    printf("Is %c a digit? The answer is: ", '5');
    TorF(isdigit('5'));

    printf("Is %c a digit? The answer is: ", '=');
    TorF(isdigit('='));

    printf("Is %s a control character? The answer is: ", "\\n");
    TorF(isctrl('\n'));

    printf("Is %c a control character? The answer is: ", 'q');
    TorF(isctrl('q'));

    printf("Is %c a lower case? The answer is: ", 'j');
    TorF(islower('j'));

    printf("Is %c a lower case? The answer is: ", 'N');
    TorF(islower('N'));

    printf("Is %c an upper case? The answer is: ", 'T');
    TorF(isupper('T'));

    printf("Is %c an upper case? The answer is: ", 'b');
    TorF(isupper('b'));

    return 0;
}
//End of program
