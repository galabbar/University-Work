//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//myfunctions.c

#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

//Inserts a node into the linked list
void insert(Node** head, int data){

    //Create a new node with the integer data assigned to it
    //It is pointing to nothing
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->idata = data;
    newNode->next = NULL;

    //The case where the linked list is empty
    if (*head == NULL){

        printf("%d was inserted!\n", data);
        *head = newNode; //The linked list head is assigned to the new node
        return; //Leaves the function
    }

    //The case where the linked list is not empty
    //A temporary node is pointing to the linked list head
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next; //The temporary node is assigned to the next node

    printf("%d was inserted!\n", data);
    temp->next = newNode; //The temporary node is assigned to the new node
}

//Inserts a node into the linked list
void insertStack(Node** head, char data){

    //Create a new node with the character data assigned to it
    //It is pointing to nothing
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->chdata = data;

    newNode->next = *head;
    *head = newNode;
}

char stackPop(Node** head){

	if (*head == NULL){

		printf("stack is empty!\n");

		return 0;
	}

	char popped_val = (*head)->chdata;
	Node* temp = *head;

	*head = (*head)->next;
	free(temp);

	return popped_val;
}

int isEmpty(Node* stack){ return stack == NULL; }

//prints the linked list recursively
void printList(Node* head){

    //Leaves the function if the list is empty
    if (head == NULL)
        return;

    //If the next node is NULL, then the function prints the data and leaves
    if (head->next == NULL){

        printf("%d\n", head->idata);
        return;
    }

    //prints the current node data and moves to the next node recursively
    printf("%d --> ", head->idata);
    return printList(head->next);
}

//Puts a string in a character linked list and check whether the paranthesis, closed brackets, and quotation marks are balanced
int stackApp(char* expr){

    int i = 0;//Index for string

    //Create a new node with the character data assigned to it
    //It is pointing to nothing
    Node* stack = (Node*)malloc(sizeof(Node));
    stack->next = NULL;

    //Goes through the string and puts all the characters in a linked list node
    while (*(expr + i) != '\0'){

        insertStack(&stack, *(expr + i));
        i++;
    }

    //Counter for paranthesis, closed brackets, quotation marks
    int Paranthesis_Count = 0;
    int ClosedBrackets_Count = 0;
    int QuotationMarks_Count = 0;

    //Goes through the linked list and counts how many paranthesis, closed brackets, quotation marks were found and are balanced
    while (!isEmpty(stack)){

        char data = stackPop(&stack);

        //increments Paranthesis_Count by 1 if the character was '(', but decrements 1 if the ')' was found
        if (data == '(')
            Paranthesis_Count++;
        if (data == ')')
            Paranthesis_Count--;

        //increments ClosedBrackets_Count by 1 if the character was '[', but decrements 1 if the ']' was found
        if (data == '[')
            ClosedBrackets_Count++;
        if (data == ']')
            ClosedBrackets_Count--;

        //increments QuotationMarks_Count by 1 for all sightings of quotation marks
        if (data == "\"")
            QuotationMarks_Count++;
    }

    /*if Paranthesis_Count does not equal to zero
    or if ClosedBrackets_Count does not equal to zero
    or if QuotationMarks_Count is not even,
    then the function returns 0 (False). Otherwise, returns 1 (True)*/

    if (Paranthesis_Count != 0)
        return 0;
    if (ClosedBrackets_Count != 0)
        return 0;
    if (QuotationMarks_Count%2 != 0)
        return 0;

    return 1;
}

//insert a node to the circular doubly queue
void enqueue(Node** head, Node** tail, int data){

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->idata = data;

	if (*head == NULL){

		*head = newNode;
		*tail = *head;

		return;
	}

	(*tail)->next = newNode;
	((*tail)->next)->back = *tail;
	*tail = (*tail)->next;

	(*tail)->next = *head;
}

//prints the queue
void printQueue(Node* head){

    //If the queue head is empty, then it leaves the function
    if (head == NULL){

        printf("The list is empty!\n");
        return;
    }

    //Goes through the queue and prints all the nodes
    Node* temp = head;
    printf("%d --> ", temp->idata);
    temp = temp->next;
    while (temp != head){

        if (temp->next == head)
            printf("%d\n", temp->idata);
        else
            printf("%d --> ", temp->idata);

        temp = temp->next;
    }
}

//Reverses the linked list
void reverseList(Node** head){

    //Leaves the function if the linked list head is empty
    if (*head == NULL){

        printf("The list is empty!\n");
        return;
    }

    //declares three nodes
    Node* prev = NULL;
    Node* current = *head;
    Node* Next = NULL;

    //reverses the linked list
    while (current != NULL){

        Next = current->next;
        current->next = prev;

        prev = current;
        current = Next;
    }

    *head = prev;
}

//Inserts a new node to the tree
void insertTreeNode(Node** root, int data){

    //If the current node is empty, the new node is inserted here
    if (*root == NULL){

        printf("%d was inserted!\n", data);

        //Create a new node with the character data assigned to it
        //Its right and left children are pointing to nothing
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->idata = data;
        newNode->left = NULL;
        newNode->right = NULL;

        //The current node is assigned to the new node
        *root = newNode;

        return; //Leaves the function
    }

    //If the current node is greater than the input node, then the tree traverses to the left child recursively
    if ((*root)->idata > data)
        return insertTreeNode(&((*root)->left), data);

    //If the current node is less than or equal to the input node, then the tree traverses to the right child recursively
    else
        return insertTreeNode(&((*root)->right), data);
}

//Finds the least value in a given sub-tree
int MinValue(Node* head){

    //Traverses through the tree's left children right before it reaches NULL
    Node* temp = head;
    while (temp->left != NULL)
        temp = temp->left;

    //Returns the data of the current node
    return temp->idata;
}

void DeleteTreeNode(Node** head, int data){

    //If the tree is empty or the node does not exist, then it leaves the function
    if (*head == NULL){

        printf("There is no such node!\n");
        return;
    }

    //If the node data is equal to the input data
    if ((*head)->idata == data){

        //The case where the current node's left and right child are both NULL
        if ((*head)->left == NULL && (*head)->right == NULL){

            printf("%d was deleted!\n", (*head)->idata);

            Node* temp = *head; //The address of the current node is stored in temp
            *head = NULL; //Current node is pointing to NULL
            free(temp); //the memory address of temp is freed
            return; //Leaves the function
        }

        //The case where only the right child is pointing to NULL
        if ((*head)->left != NULL && (*head)->right == NULL){

            printf("%d was deleted!\n", (*head)->idata);

            Node* temp = *head; //The address of the current node is stored in temp
            *head = (*head)->left; //The current node is assigned to its left child
            free(temp); //the memory address of temp is freed
            return; //Leaves the function
        }

        if ((*head)->left == NULL && (*head)->right != NULL){

            printf("%d was deleted!\n", (*head)->idata);

            Node* temp = *head; //The address of the current node is stored in temp
            *head = (*head)->right; //The current node is assigned to its right child
            free(temp); //the memory address of temp is freed
            return; //Leaves the function
        }

        if ((*head)->left != NULL && (*head)->right != NULL){

            (*head)->idata = MinValue((*head)->right); //Assigns the current node data to the least largest data from its right child's sub-tree
            return DeleteTreeNode(&((*head)->right), MinValue((*head)->right)); //Deletes the least largest data from its right child's sub-tree
        }
    }

    //if the current node data is lesser than the input data, the function recursively traverses to the left child
    if ((*head)->idata > data)
        return DeleteTreeNode(&((*head)->left), data);

    //if the current node data is larger than the input data, the function recursively traverses to the right child
    if ((*head)->idata < data)
        return DeleteTreeNode(&((*head)->right), data);
}

//prints the tree in in-order format
void printTreeInOrder(Node* root){

    //if the current node is Null, then it leaves the function or the recursive call
    if (root == NULL)
        return;

    printTreeInOrder(root->left); //Recursively move to the left child
    printf("%d ", root->idata); //prints current node data
    printTreeInOrder(root->right); //Recursively move to the right child
}
