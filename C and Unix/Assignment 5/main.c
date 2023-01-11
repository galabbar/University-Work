//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//main.c

#include <stdio.h>
#include "myfunctions.h"

int main(){

    printf("Regular Linked List:\n\n");

    Node* head = NULL;

    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 6);
    insert(&head, 8);
    insert(&head, 3);
    insert(&head, 5);

    printf("The list printed: ");
    printList(head);

    printf("The list being reversed and printed: ");
    reverseList(&head);
    printList(head);

    printf("\n\n");

    printf("enqueue a circular queue:\n\n");

    head = NULL;
    Node* tail = NULL;

    enqueue(&head, &tail, 1);
    enqueue(&head, &tail, 2);
    enqueue(&head, &tail, 3);
    enqueue(&head, &tail, 4);
    enqueue(&head, &tail, 5);

    printf("printing the queue: ");
    printQueue(head);

    printf("\n\n");

    printf("stack function:\n\n");

    char* str = (char*)malloc(50);

    str = " ([]\"\"\"\"[]) ";

    printf("Does the string %s have balanced pairs? The answer is: ", str);
    if (stackApp(str))
        printf("True!\n");
    else
        printf("False!\n");

    printf("\n\n");

    printf("Binary Search Tree:\n\n");

    head = NULL;

    insertTreeNode(&head, 7);
    insertTreeNode(&head, 5);
    insertTreeNode(&head, 12);
    insertTreeNode(&head, 3);
    insertTreeNode(&head, 6);
    insertTreeNode(&head, 10);
    insertTreeNode(&head, 30);

    printf("The tree printed in-order: ");
    printTreeInOrder(head);
    printf("\n");

    DeleteTreeNode(&head,30);

    printf("\nThe tree printed in-order: ");
    printTreeInOrder(head);
    printf("\n");

    return 0;
}

//Compile Command: gcc main.c -o main
//Run Command: ./main
