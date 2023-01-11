#include<stdio.h>
#include<stdlib.h>

struct queueNode {
	char data;
	struct queueNode *next;
};

int isEmptyQ(struct queueNode *first){
	return (first==NULL);
}

void enqueue (struct queueNode **first,struct queueNode **last,char value){
	struct queueNode *temp;
	temp=malloc(sizeof(struct queueNode));
	if (temp !=NULL){//memory is not full
		temp->data=value;
		temp->next=NULL;

		if (isEmptyQ(*first)){ //if empty insert node at head
			*first=temp;
		}
		else {
			(*last)->next=temp;
		}
		*last=temp;
	}
}

char dequeue (struct queueNode **first, struct queueNode **last){
	struct queueNode *temp;
	char value;
	value=(*first)->data;
	temp=*first;
	*first=(*first)->next;
	if(*first==NULL)
		*last=NULL;
	free(temp);
	return value;
}
