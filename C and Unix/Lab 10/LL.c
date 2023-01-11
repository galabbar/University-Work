//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//LL.c

#include <stdio.h>
#include <stdlib.h>

struct node{

	int data;
	struct node* next;
	struct node* prev;
};


void insertUntilNeg(struct node** Last){

	int Data;
	printf("Enter a new node data: ");
	scanf("%d", &Data);
	
	while (Data > 0){
	
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = Data;
		
		if (*Last == NULL){
			(*Last) = newNode;
			(*Last)->next = NULL;
		} 
		
		else{
		
			(*Last)->prev = newNode;
			((*Last)->prev)->next = *Last;
			*Last = (*Last)->prev;
			
		}
		
		printf("Enter a new node data: ");
		scanf("%d", &Data);
	}
	
	(*Last)->prev = NULL;
} 

void DeleteAllEven(struct node** head){

	if (*head == NULL){
		
		printf("The lsit is Empty!\n");
		return;
	}
	
	if ((*head)->next == NULL && (*head)->data % 2 == 0){
	
		printf("%d was removed.\n", (*head)->data);	
		struct node* temp = *head;
		*head = NULL;
		free(temp);
		return;
	}
	
	struct node* temp = *head;
	while (temp->next != NULL){
	
		if (temp->data % 2 == 0){
			
			printf("%d was removed.\n", (*head)->data);
			struct node* temp2 = temp;
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
			free(temp2);
		}
		
		temp = temp->next;
	}
	
	if (temp->data % 2 == 0)
		temp = NULL;
}

void DeleteEven(struct node** head){

	if (*head == NULL)
		return;
		
	if ((*head)->data % 2 == 0){
		
		struct node* temp = *head;
		*head = (*head)->next;
		free(temp);
		
		DeleteEven(&(*head));
	}
	
	DeleteEven(&((*head)->next));
}

void DisplayRec(struct node* head){

	if (head->next == NULL){
	
		printf("%d\n", head->data);
		return;
	}
	
	printf("%d --> ", head->data);
	return DisplayRec(head->next);
}

int main(){

	struct node* head = NULL;
	
	insertUntilNeg(&head);
	DisplayRec(head);
	DeleteEven(&head);
	DisplayRec(head);
	return 0;
}
