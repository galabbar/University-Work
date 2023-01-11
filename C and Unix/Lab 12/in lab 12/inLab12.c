#include <stdio.h>
#include <stdlib.h>
#include "Trees.h"

int main(){

    FILE* F = fopen("data.txt", "r");
    Node* root = NULL;

    if (!F){

        printf("The file is not open!\n");
        exit(1);
    }

    while (!feof(F)){

        int data;
        fscanf(F, "%d", &data);

        insertNode(&root, data);
    }

    fclose(F);
    F = fopen("output.txt", "w");

    printEven(root, F);
    fclose(F);

    F = fopen("output.txt", "r");

    if (!F){

        printf("The file is not open!\n");
        exit(1);
    }

    printf("The Nodes with even values printed in descending order: ");
    while (1){

        int data;
        fscanf(F, "%d", &data);

        if (feof(F)) break;

        printf("%d ", data);
    }
    puts("");

    return 0;
}
