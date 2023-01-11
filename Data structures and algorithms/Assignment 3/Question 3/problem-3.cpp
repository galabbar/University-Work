//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Problems: 3 - 4 - 5 - 6
//problem-3.cpp

//Let n be the number of nodes in the binary tree

#include <iostream>
#include <queue>
using namespace std;

//Node class
struct Node{

    //Constructor
    //Makes every child of a node point to null
    //Assigns the user input as data
    Node(int Data): data(Data)
    {
        this->right = nullptr;
        this->left = nullptr;
    }

    Node* right;
    Node* left;
    int data;
};

//Binary Search Tree Class
class BST{

public:

    //Constructor
    //Makes the root point to null when instantiating a new BST object
    BST()
    {
        this->root = nullptr;
    }

//Problem 3
/****************************************************************************************/

    //Returns true if the input data is found within the tree
    //Time Complexity: O(log(n)) because searching goes through the nodes by cutting down the list in multiple halves until it reaches its destination
    bool Search(int key){

        Node* temp = root; //temp node to hold the root (copy of the root, not reference)

        return searchRec(key, temp); //Calls searchRec to return true or false
    }

    //Adds a node with user input data to the tree
    //Time Complexity: O(log(n)) because going through the nodes means cutting down the list in multiple halves until it reaches its destination
    void add(int key){addRec(key, root);} //Calls addRec to add a node to the tree. The root is being passed by reference.

    //Deletes a node from the tree
    //Time Complexity: O(log(n)) because going through the nodes means cutting down the list in multiple halves until it reaches the desired node
    void Delete(int key){deleteRec(root, key);} //Calls deleteRec to remove a node from the tree. The root is being passed by reference.

    //Prints the tree in order
    //Time Complexity: O(n) since it goes through all the whole tree
    void printInorder(){

        Node* temp = root; //temp node to hold the root (copy of the root, not reference)

        Inorder(temp); //Calls the Inorder function to print the tree in order

        cout << endl;
    }

    //Prints the tree post order
    //Time Complexity: O(n) since it goes through all the whole tree
    void printPostorder(){

        Node* temp = root; //temp node to hold the root (copy of the root, not reference)

        Postorder(temp); //Calls the Postorder function to print the tree post order

        cout << endl;
    }

    //Prints the tree pre-order
    //Time Complexity: O(n) since it goes through all the whole tree
    void printPreorder(){

        Node* temp = root; //temp node to hold the root (copy of the root, not reference)

        Preorder(temp); //Calls the Preorder function to print the tree pre-order

        cout << endl;
    }

/****************************************************************************************/

    //problem 4
    //Counts and returns the number of leaves in the binary tree
    //Time Complexity: O(n) since it goes through all the whole tree
    int LeafCount(){

        int Count = 0; //Counter that counts the number of leaves

        Node* temp = root; //temp node to hold the root (copy of the root, not reference)

        LeafCountRec(temp, Count); //Calls the function leafCountRec to count the number of leaves. Count is passed by reference

        return Count; //Returns the number of leaves
    }

    //problem 5
    //Finds and returns the kth smallest element from the binary tree.
    //Time Complexity: O(n) since it goes through all the whole tree
    int KthSmallest(int k){

        //Checks if the root is null. If it was, the function would end and returns nothing
        if (root == nullptr)
            cout << "The tree is Empty!\n";

        //The case where the tree is not empty.
        else{

            //Queue to hold all the data from the tree in (in order) sequence
            queue<int> Q; //The data is positioned from the smallest to the largest
            Node* temp = root; //temp node to hold the root (copy of the root, not reference)

            traverse(temp, Q); //Calls the traverse function to store the data in the queue. Queue is passed by reference

            //goes through the queue and pops the front k - 1 times
            for (int i = 1; i < k; i++)
                Q.pop();

            return Q.front(); //Returns the front (the kth element)
        }
    }

    //problem 6
    //Checks if the binary tree is complete. Returns true if it is. Otherwise, returns false.
    //Time Complexity: O(n) since it goes through all the whole tree
    bool isComplete(){

        //If the tree is empty, then by definition, it is complete. Returns true
        if (root == nullptr)
            return true;

        bool isNotComplete = false; //Boolean value that checks if the tree is empty or not. It is set to false for now

        queue<Node*> Q; //Queue to store the nodes in descending order
        Q.push(root); //enqueues the root

        //Goes through the tree and checks whether it is complete or not
        while (!Q.empty()){

            Node* temp = Q.front(); //Temporary node to hold the front of the queue
            Q.pop(); //The queue is popped (handles the descending movement across the tree)

            /* Since isNotComplete starts out as false, then the queue just enqueues the left and right children.
               If it happens to find a null pointer between two non-null pointing nodes, then the tree is not complete.
               isNotComplete switches to true and the function returns returns false.

               If the queue reached a null pointer and no other non-null pointing nodes, then it will go through the loop until it ends and returns true.
            */

            //checks whether the temp node is null
            if (temp == nullptr)
                isNotComplete = true; //isNotComplete is switched to tue

            //if temp is not empty
            else{

                //If isNotComplete is true while temp is not empty, then the tree is not complete. Returns false
                if (isNotComplete)
                    return false;

                Q.push(temp->left); //enqueues the left child first
                Q.push(temp->right); //enqueues the second child next
            }
        }

        //If the end of the loop has been reached, then the tree is a complete tree. Returns true.
        return true;
    }

private: //Encapsulated members and functions

    Node* root; //Holds the root node for the tree

    //adds a node with data equal to key to the tree by searching for its destination recursivly
    //Time Complexity: O(log(n)) because going through the nodes means cutting down the list in multiple halves until it reaches its destination
    void addRec(int key, Node*& node){

    //Checks if the current node points to null
    if (node == nullptr){

        Node* NewNode = new Node(key); //creates new node with data equal to key

        node = NewNode; //The current node is assigned to the new node

        cout << "Node with data " << key << " is added!\n";

        return; //Leaves the function
    }

    //If the current node data is greater than or equal to key
    if (node->data >= key)
        return addRec(key, node->left); //Moves to the left node recursivly

    //If the current node data is less than key
    else
        return addRec(key, node->right); //Moves to the right node recursivly

    }

    //Checks if key is a data for a node within the tree. Returns true if the node exists. Otherwise, returns false.
    //Time Complexity: O(log(n)) because searching goes through the nodes by cutting down the list in multiple halves until it reaches its destination
    bool searchRec(int key, Node* node){

        //if the current node is null, then the node does not exist. Returns false
        if (node == nullptr)
            return false;

        //If the current node is equal to the key value, then it returns true
        if (key == node->data)
            return true;

        //If the current node data is greater than or equal to the key value
        if ( node->data >= key)
            return searchRec(key, node->left); //Moves to the left child recursivly

        //If the current node data is less than the key value
        else
            return searchRec(key, node->right); //Moves to the right child recursivly
    }

    //Prints the tree in order
    //Time Complexity: O(n) Since it goes through the whole tree
    void Inorder(Node* node){

        //if the current node is pointing to null
        if (node == nullptr)
            return; //leaves function or recursive call

        Inorder(node->left); //recursivly move to the left child

        cout << node->data << "  "; //prints the data of the current node

        Inorder(node->right); //recursivly move to the right child
    }

    //Prints the tree in post order
    //Time Complexity: O(n) Since it goes through the whole tree
    void Postorder(Node* node){

        //if the current node is pointing to null
        if (node == nullptr)
            return; //leaves function or recursive call

        Postorder(node->left); //recursivly move to the left child

        Postorder(node->right); //recursivly move to the right child

        cout << node->data << "  "; //prints the data of the current node
    }

    //Prints the tree in post order
    //Time Complexity: O(n) Since it goes through the whole tree
    void Preorder(Node* node){

        //if the current node is pointing to null
        if (node == nullptr)
            return; //leaves function or recursive call

        cout << node->data << "  "; //prints the data of the current node

        Preorder(node->left); //recursivly move to the left child

        Preorder(node->right); //recursivly move to the right child
    }

    //Finds the node data with the smallest value after a certain node
    //Time Complexity: O(log(n)) since it goes left using a fraction of n steps
    int MinValue(Node* node){

        Node* temp = node; //temp node to hold the root (copy of the root, not reference)

        //Moves left until it reaches the node that points to null
        while (temp->left != nullptr)
            temp = temp->left; //temp is temp's left child

        return temp->data; //Returns the node data of the far left child
    }

    //Deletes a node from the tree
    //Time Complexity: O(log(n)) because going through the nodes means cutting down the list in multiple halves until it reaches the desired node
    void deleteRec(Node*& node, int key){

        //if the node with data equal to key is not found
        if (node == nullptr){

            cout << "No such Node exists with data " << key <<endl; //prints message

            return; //leaves function
        }

        //If the current node data is equal to the key value, then the deletion process begins
        if (node->data == key){

            //If the current node has no children
            if (node->left == nullptr && node->right == nullptr){

                cout << "node with data " << key << " succesfully deleted\n";

                Node* temp = node; //Stores the current node address in temp
                delete temp; //deletes temp (frees up the memory)

                node = nullptr; //current node points to null

                return; //leaves function
            }


            //If the current node only has a left child
            if (node->left != nullptr && node->right == nullptr){

                cout << "node with data " << key << " succesfully deleted\n";

                Node* temp = node->left; //stores the current node's left child's address in temp

                node = node->left; //Current is assigned to its left child

                delete temp; //deletes temp (frees up the memory)

                return; //Leaves the function
            }

            //If the current node only has a right child
            if (node->left == nullptr && node->right != nullptr){

                cout << "node with data " << key << " succesfully deleted\n";

                Node* temp = node->right; //stores the current node's right child's address in temp

                node = node->right; //Current is assigned to its right child

                delete temp; //Current is assigned to its left child

                return; //Leaves the function
            }


            //If the node has both a right and a left child
            if (node->left != nullptr && node->right != nullptr){

                node->data = MinValue(node->right); //Current node data is the smallest node data value after its right child

                deleteRec(node->right, MinValue(node->right)); //deleteRec is called to remove the node with smallest data value after current node's right child

                cout << "node with data " << key << " succesfully deleted\n";

                return; //Leaves function
            }
        }

        //If the node data is greater than the key value
        if (node->data > key)
            return deleteRec(node->left, key); //Recursivly move to the left child

        //If the node data is less than the key value
        if (node->data < key)
            return deleteRec(node->right, key); //Recursivly move to the right child
    }

    //problem 4
    //Counts and returns the number of leaves in the binary tree
    //Time Complexity: O(n) since it goes through all the whole tree
    void LeafCountRec(Node* node, int& Count){

        //if the current node points to null
        if (node == nullptr)
            return; //leaves the function or recursive call

        //If the node's left child and right child are both empty, then it is a leaf
        if (node->right == nullptr && node->left == nullptr){

            Count += 1; //increment the counter by one

            return; //leaves the function or recursive call
        }

        //if the current node only has a right child
        if (node->right != nullptr && node->left == nullptr)
            LeafCountRec(node->right, Count); //Recusrivly move to the right child

        //if the current node only has a left child
        if (node->right == nullptr && node->left != nullptr)
            LeafCountRec(node->left, Count); //Recusrivly move to the right child

        //if the current node has both left and right children
        if (node->right != nullptr && node->left != nullptr){

            LeafCountRec(node->left, Count); //Recusrivly move to the left child

            LeafCountRec(node->right, Count); //Recusrivly move to the right child

            return; //leaves the function or recursive call
        }
    }

    //Function that traverses through the tree in order, and enqueues all node data into the queue
    //By the end of the function, the queue has all the tree's node data in ascending order
    //Time Complexity: O(n) Since it goes through the whole tree
    void traverse(Node* node, queue<int>& Q){

        //If the current node is empty
        if (node == nullptr)
            return; //leaves the function or recursive call

        traverse(node->left, Q); //Recusrivly move to the left child
        Q.push(node->data); //enqueues the current node data into the queue
        traverse(node->right, Q); //Recusrivly move to the right child
    }
};

//Beginning of program
int main(){

    BST tree;

    tree.add(7);
    tree.add(12);
    tree.add(5);
    tree.add(3);
    tree.add(6);
    tree.add(10);
    tree.add(30);

    cout << "Is the there a node with data 12 in the tree? The answer is: ";

    if (tree.Search(12))
        cout << "True\n";
    else
        cout << "False\n";

    cout << "Is the there a node with data 100 in the tree? The answer is: ";

    if (tree.Search(100))
        cout << "True\n";
    else
        cout << "False\n";

    cout << "Printing in order: ";
    tree.printInorder();

    cout << "Printing post order: ";
    tree.printPostorder();

    cout << "Printing pre-order: ";
    tree.printPreorder();

    cout << "The number of leaves is " << tree.LeafCount() << endl;

    cout << "The 4th smallest element is " << tree.KthSmallest(4) << endl;

    cout << "Is the tree complete? The answer is: ";

    if (tree.isComplete())
        cout << "True\n";
    else
        cout << "False\n";

    tree.Delete(7);

    cout << "Is the there a node with data 7 in the tree? The answer is: ";

    if (tree.Search(7))
        cout << "True\n";
    else
        cout << "False\n";

    cout << "Is the there a node with data 30 in the tree? The answer is: ";

    if (tree.Search(30))
        cout << "True\n";
    else
        cout << "False\n";

    cout << "Printing in order: ";
    tree.printInorder();

    cout << "Printing post order: ";
    tree.printPostorder();

    cout << "Printing pre-order: ";
    tree.printPreorder();

    cout << "The number of leaves is " << tree.LeafCount() << endl;

    cout << "The 4th smallest element is " << tree.KthSmallest(4) << endl;

    cout << "Is the tree complete? The answer is: ";
    if (tree.isComplete())
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
//End of program
