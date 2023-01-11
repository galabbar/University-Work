#include <stdio.h>
#include "BST.c"

int SumOfOddNodes(Node* tree){

    int sum = 0;

    SumOfOddNodesHelper(tree, &sum);

    return sum;
}

void SumOfOddNodesHelper(Node* tree, int* sum){

    if (tree == NULL)
        return;

    if (tree->data % 2 != 0)
        *sum = *sum + tree->data;

    SumOfOddNodesHelper(tree->left, sum);
    SumOfOddNodesHelper(tree->right, sum);
}

int main(){

    Node* root = NULL;

    insertTreeNode(&root, 1);
    insertTreeNode(&root, 2);
    insertTreeNode(&root, 3);
    insertTreeNode(&root, 4);
    insertTreeNode(&root, 5);

    printf("\n\n");
    printf("The sum of all nodes with odd data is %d\n", SumOfOddNodes(root));
}
