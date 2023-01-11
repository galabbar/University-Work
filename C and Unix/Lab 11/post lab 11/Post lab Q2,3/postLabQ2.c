#include <stdio.h>
#include "BST.c"

int NumberOfNodes(Node* tree){

    int count = 0;
    NumofNodesHelper(tree, &count);

    return count;
}

void NumofNodesHelper(Node* tree, int* counter){

    if (tree == NULL)
        return;

    NumofNodesHelper(tree->left, counter);
    *(counter) += 1;
    NumofNodesHelper(tree->right, counter);
}

int main(){

    Node* root = NULL;

    insertTreeNode(&root, 1);
    insertTreeNode(&root, 2);
    insertTreeNode(&root, 3);
    insertTreeNode(&root, 4);
    insertTreeNode(&root, 5);

    printf("\n\n");
    printf("There are %d nodes in this binary tree\n", NumberOfNodes(root));

    return 0;
}
