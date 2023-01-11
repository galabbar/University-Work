#include <stdio.h>
#include <stdlib.h>
#include "Trees.h"

void insertNode(Node** root, int data){

    if (*root == NULL){

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;

        *root = newNode;
        return;
    }

    if ((*root)->data > data)
        return insertNode(&((*root)->left), data);

    else
        return insertNode(&((*root)->right), data);
}

void printEven(Node* root, FILE* F){

    if (root == NULL)
        return;

    printEven(root->right, F);

    if (root->data % 2 == 0)
        fprintf(F, "%d\n", root->data);

    printEven(root->left, F);
}
