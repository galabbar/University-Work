//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//inLab11.c

#include <stdio.h>
#include "stacks.c"
#include "queues.c"

int isPalindrome(char* str){

    struct stackNode *S = NULL;
    struct queueNode *First = NULL, *Last = NULL;
    int i = 0;

    while (*(str + i) != '\0'){

        push(&S, *(str + i));
        enqueue(&First, &Last , *(str + i));
        i++;
    }

    int size = i/2;

    while (i != size){

        if (dequeue(&First, &Last) != pop(&S))
            return 0;

        i--;

    }

    return 1;
}

int main(){

    char *str = (char*)malloc(50);

    printf("Enter a string: ");
    gets(str);

    printf("\n\n");

    if (isPalindrome(str))
        printf("It is a palindrome!\n");
    else
        printf("It is not a palindrome.\n");

    return 0;
}
