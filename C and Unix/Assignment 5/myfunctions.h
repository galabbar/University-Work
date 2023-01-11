//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//myfunctions.h

#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

//Node Struct
typedef struct node{

    //integer and character data
    int idata;
    char chdata;

    //Node struct members
    struct node* next;
    struct node* back;
    struct node* left;
    struct node* right;

}Node;

//function prototypes

void insert(Node** head, int data);
void insertStack(Node** head, char data);
char stackPop(Node** head);
void printList(Node* head);
int stackApp(char* expr);
void enqueue(Node** head, Node** tail, int data);
void printQueue(Node* head);
void reverseList(Node** head);
void insertTreeNode(Node** root, int data);
int GetMinValue(Node* head);
void deleteTreeNode(Node** root, int data);
void printTreeInOrder(Node* root);

#endif // MYFUNCTIONS_H_INCLUDED
