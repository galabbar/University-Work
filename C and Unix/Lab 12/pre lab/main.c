//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//main.c

#include <stdio.h>
#include <stdlib.h>
#include "Trees.h"

int main(){

    FILE* F;
    F = fopen("data.txt", "r");

    if (F == NULL){
        printf("The file is not open!\n");
        exit(0);
    }

    Node* head = NULL;

    while (!feof(F)){

        int data;

        fscanf(F, "%d", &data);
        insertTreeNode(&head, data);
    }

    fclose(F);
    F = fopen("output.txt", "w");

    inOrder(head, F);
    fclose(F);

    F = fopen("output.txt", "r");

    printf("The tree printed in-order: ");
    while (1){
        int data;

        fscanf(F, "%d", &data);

        if (feof(F))
            break;

        printf("%d ", data);

        if (data == '\n') break;
    }

    fclose(F);

    return 0;
}
