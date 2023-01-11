//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Trees.h

#include <stdio.h>
#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

typedef struct node{

    struct node* right;
    struct node* left;
    int data;

}Node;

void insertTreeNode(Node**,int);
void inOrder(Node*, FILE*);



#endif // TREES_H_INCLUDED
