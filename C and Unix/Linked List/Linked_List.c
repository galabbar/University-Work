#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node* next;

}Node;

Node* init(){

    Node* first;
    first = NULL;

    return first;
}

void insert(Node** head, int data){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL){

        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void Delete(Node** head, int data){

    if ((*head)->data == data){

        Node* temp = *head;
        *head = (*head)->next;
        free(temp);

        return;
    }

    return Delete(&((*head)->next), data);
}

void Display(Node* head){

    if (head == NULL){

        printf("The list is empty!\n");
        return;
    }

    Node* temp = head;

    while (temp != NULL){

        if (temp->next == NULL)
            printf("%d\n", temp->data);

        else
            printf("%d --> ", temp->data);

        temp = temp->next;
    }
}

int main(){

    Node* head = init();

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    Display(head);

    Delete(&head, 3);

    Display(head);

    return 0;
}
