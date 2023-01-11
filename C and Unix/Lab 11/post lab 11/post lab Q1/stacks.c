#include<stdio.h>
#include<stdlib.h>

struct stackNode {
	char data;
	struct stackNode *next;
};

void push(struct stackNode **topStack,char x){
	struct stackNode *temp;
	temp=malloc(sizeof(struct stackNode));
	if(temp!=NULL)//memory is not full
	{
		temp->data=x;
		temp->next=*topStack;
		*topStack=temp;
	}
	else
		printf("Memory is Full!\n");
}

int pop(struct stackNode **topStack){
	struct stackNode *temp;
	char popVal;
	temp=*topStack;
	popVal=(*topStack)->data;
	*topStack=(*topStack)->next;
	free(temp);
	return popVal;
}

int isEmpty(struct stackNode *topStack){
	return (topStack==NULL);
}

int Top(struct stackNode* stack){ return stack->data;}
