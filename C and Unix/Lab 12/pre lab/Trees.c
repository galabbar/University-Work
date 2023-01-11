//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Trees.c

#include <stdio.h>
#include <stdlib.h>
#include "Trees.h"

void insertTreeNode(Node** head, int data){

    if (*head == NULL){

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        *head = newNode;

        (*head)->right = NULL;
        (*head)->left = NULL;
        return;
    }

    if ((*head)->data < data)
        return insertTreeNode(&((*head)->right), data);
    else
        return insertTreeNode(&((*head)->left), data);
}

void inOrder(Node* head, FILE* F){

    if (head == NULL)
        return;

    inOrder(head->left, F);
    fprintf(F,"%d\n", head->data);
    inOrder(head->right, F);
}
