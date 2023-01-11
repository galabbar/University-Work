//Name; Ghazi Najeeb Al-Abbar
//ID: 2181149814
//PostLab10.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{

    char data;
    struct node* next;

};

void insert(struct Node** head, char data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL){

        *head = newNode;
        (*head)->next = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void DeleteRec(struct Node** head){

    if (*head == NULL)
        return;

    if ( !(isalpha((*head)->data)) ){

        if ((*head)->data != ' '){

            struct Node* temp = *head;
            *head = (*head)->next;
            free(head);

            return DeleteRec(&(*head));
        }
    }

    if ((*head)->data != ' ')
        if (!((*head)->data >= 'A' && (*head)->data <= 'Z'))
            (*head)->data = (*head)->data - ('a' - 'A');

    return DeleteRec(&((*head)->next));
}

void PrintList(struct Node* head){

    if (head == NULL){

        printf("The list is empty!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL){

        if (temp->next == NULL)
            printf("%c\n", temp->data);
        else
            printf("%c", temp->data);

        temp = temp->next;
    }
}

int main(){

    struct Node* head = NULL;
    char* str = (char*)malloc(50);
    int i = 0;

    printf("Enter your line of text: ");
    gets(str);
    //scanf("%s", str);

    while (*(str + i) != '\0'){

        insert(&head, *(str + i));
        i++;
    }

    DeleteRec(&head);
    printf("\nYour output: ");
    PrintList(head);

    return 0;

}
