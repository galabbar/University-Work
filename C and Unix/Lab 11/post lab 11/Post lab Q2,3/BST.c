#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node* left;
    struct node* right;
}Node;

void insertTreeNode(Node** root, int data){

    //If the current node is empty, the new node is inserted here
    if (*root == NULL){

        printf("%d was inserted!\n", data);

        //Create a new node with the character data assigned to it
        //Its right and left children are pointing to nothing
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        //The current node is assigned to the new node
        *root = newNode;

        return; //Leaves the function
    }

    //If the current node is greater than the input node, then the tree traverses to the left child recursively
    if ((*root)->data > data)
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
    return temp->data;
}

void DeleteTreeNode(Node** head, int data){

    //If the tree is empty or the node does not exist, then it leaves the function
    if (*head == NULL){

        printf("There is no such node!\n");
        return;
    }

    //If the node data is equal to the input data
    if ((*head)->data == data){

        //The case where the current node's left and right child are both NULL
        if ((*head)->left == NULL && (*head)->right == NULL){

            printf("%d was deleted!\n", (*head)->data);

            Node* temp = *head; //The address of the current node is stored in temp
            *head = NULL; //Current node is pointing to NULL
            free(temp); //the memory address of temp is freed
            return; //Leaves the function
        }

        //The case where only the right child is pointing to NULL
        if ((*head)->left != NULL && (*head)->right == NULL){

            printf("%d was deleted!\n", (*head)->data);

            Node* temp = *head; //The address of the current node is stored in temp
            *head = (*head)->left; //The current node is assigned to its left child
            free(temp); //the memory address of temp is freed
            return; //Leaves the function
        }

        if ((*head)->left == NULL && (*head)->right != NULL){

            printf("%d was deleted!\n", (*head)->data);

            Node* temp = *head; //The address of the current node is stored in temp
            *head = (*head)->right; //The current node is assigned to its right child
            free(temp); //the memory address of temp is freed
            return; //Leaves the function
        }

        if ((*head)->left != NULL && (*head)->right != NULL){

            (*head)->data = MinValue((*head)->right); //Assigns the current node data to the least largest data from its right child's sub-tree
            return DeleteTreeNode(&((*head)->right), MinValue((*head)->right)); //Deletes the least largest data from its right child's sub-tree
        }
    }

    //if the current node data is lesser than the input data, the function recursively traverses to the left child
    if ((*head)->data > data)
        return DeleteTreeNode(&((*head)->left), data);

    //if the current node data is larger than the input data, the function recursively traverses to the right child
    if ((*head)->data < data)
        return DeleteTreeNode(&((*head)->right), data);
}
