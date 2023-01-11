#include <stdio.h>
#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

typedef struct node{

    struct node* left;
    struct node* right;
    int data;

}Node;

void insertNode(Node**,int);
void printEven(Node*,FILE*);


#endif // TREES_H_INCLUDED
