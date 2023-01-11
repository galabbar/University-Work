#include <stdio.h>
#include "stacks.c"

int PostfixExpression(char* str){

    struct stackNode* MainStack = NULL;
    struct stackNode* tempStack = NULL;
    int i = 0;
    int Result = 0;

    while (*(str + i) != '\0'){

        push(&tempStack, *(str + i));
        i++;
    }

    while (!isEmpty(tempStack))
        push(&MainStack, pop(&tempStack));

    while (!isEmpty(MainStack)){

        int x = pop(&MainStack);
        Result = x;

        push(&tempStack, x);

        if (x == '+'){

            pop(&tempStack);

            int val1 = pop(&tempStack) - '0';
            int val2 = pop(&tempStack) - '0';

            push(&MainStack, val1 + val2 + '0');

            while (!isEmpty(tempStack))
                push(&MainStack, pop(&tempStack));

            continue;
        }

        if (x == '-'){

            pop(&tempStack);

            int val1 = pop(&tempStack) - '0';
            int val2 = pop(&tempStack) - '0';

            push(&MainStack, (val2 - val1) + '0');

            while (!isEmpty(tempStack))
                push(&MainStack, pop(&tempStack));

            continue;
        }

        if (x == '*'){

            pop(&tempStack);

            int val1 = pop(&tempStack) - '0';
            int val2 = pop(&tempStack) - '0';

            push(&MainStack, (val2 * val1) + '0');

            while (!isEmpty(tempStack))
                push(&MainStack, pop(&tempStack));

            continue;
        }

        if (x == '/'){

            pop(&tempStack);

            int val1 = pop(&tempStack) - '0';
            int val2 = pop(&tempStack) - '0';

            if (val1 == 0){

                printf("There is a division by zero in your expression!\n");

                return -999;
            }

            push(&MainStack, (val2 / val1) + '0');

            while (!isEmpty(tempStack))
                push(&MainStack, pop(&tempStack));

            continue;
        }
    }

    return Result - '0';
}

int main(){

    char str[10] = "823+*4/";

    printf("Your expression accumulates to: %d", PostfixExpression(str));

    return 0;
}
