//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-1.cpp

//Stacks, Queues, and LinkedLists implemented using nodes
//Let n be the number of nodes

#include <iostream>
using namespace std;

class LinkedList{

  public:

  //Constructor
  LinkedList()
  {
    this->next = nullptr; //makes the next node after the newly constructed node point to nothing
  }

  //Returns true if the list is empty
  //Time Complexity: O(1) because there is only one command
  bool isEmpty(){ return first == nullptr;}

  //Adds a node to the tail of the list
  //Time Complexity: O(n) because the size of the list is variable, and the loop iterates at least n times
  void add(int Data){

      LinkedList* newPtr = new LinkedList(); //creates a new node
      newPtr->data = Data;//Makes the node data equal to the user input data

      LinkedList* temp = first; //temporary node to hold the first node

      //Checks if the list is empty
      //if that's the case, then the the first node would equal newPtr
      if (isEmpty())
      {
       first = newPtr;

       cout << Data << " was added!\n";

       return; //leaves function
      }

      //The case where the list is not empty
      //The loop goes through the list just until the next node points to nothing
      while (temp->next != nullptr)
        temp = temp->next; //goes to the next node

      temp->next = newPtr; //The new node is added after last node

      cout << Data << " was added!\n";
    }

    //Looks for a node with data x to remove. Prints an error message if there is no node with data x
    //Time Complexity: O(n) because the loop iterates at least n times
    void Remove(int x){

        //Checks if the list is empty
        if (isEmpty()){
            cout << "There are no elements in this Linked List!\n";
            return; //leaves the function if the list is empty
        }

        //Checks if the first node is x
        if (first->data == x)
        {
            //checks if the first node is the only node
            if (first->next == nullptr){
                first = nullptr; //points the first node no nothing

                cout << x << " was removed from the linked List.\n";

                return; //leaves the function
            }

            //checks if the first node is not the only node
            else{

                first = first->next; //removes the first node and makes the second node the first

                cout << x << " was removed from the linked List.\n";

                return; //leaves function
            }
        }

        bool isElement = false;//boolean value that is false when x is not a data for a node, and true if it was
        LinkedList* temp = first;//temporary node to hold the first node

        //goes through the list and checks if x is a data
        while(temp->next != nullptr){

            //checks if the data of the next node is x
            //if it is the case, then the loop breaks
            if (temp->next->data == x){

                isElement = true;

                break;
            }

            temp = temp->next; //goes to the next node
        }

        //checks if isElement is true
        if (isElement){

            temp->next = temp->next->next; //Makes the next node equal to the node next to the next node

            cout << x << " was removed from the linked List.\n";

            return; //leaves the function
        }

        //The case where x is not in the List
        //prints a message telling the user that the element does not exist
        cout << "There is no element with data " << x << "!\n";
    }

    //returns true if x is the data of one of the elements. False if it is not
    //Time Complexity: O(n) because the loop iterates at least n times
    bool search(int x){

        LinkedList* temp = first; //temporary node to hold the first node

        //goes through the list and checks whether x is in the list or not
        while (temp != nullptr){

            //checks if x is the data of the current node
            if (temp->data == x)
                return true; //returns true if x is the current data

            temp = temp->next; //goes to next node
        }

        //if x is not in the list, then return false
        return false;
    }

    //Returns the number of nodes in the list. Will return 0 if the list is empty
    //Time Complexity: O(n) because the loop iterates at least n times
    int Size(){

        LinkedList* temp = first; //temporary node to hold the first node
        int count = 0; //the counter starts at 0

        //goes through the list and counts each element
        while (temp != nullptr){

            count++; //increments the counter
            temp = temp->next; //goes to the next node
        }

        return count; //returns the size
    }

       /*Print function*/
    void print(){

        if (isEmpty()){
            cout << "Linked list is empty!\n";
            return;
        }

        LinkedList* temp = first;

        while (temp != nullptr){

            if (temp->next == nullptr)
                cout << temp->data << endl;
            else
                cout << temp->data << " -->";

            temp = temp->next;
        }
    }

  private: //encapsulated attributes

  LinkedList* first = nullptr; //first node
  LinkedList* next; //Next node. it could be a nullptr
  int data; //The data stored in the node
};

class Stack{ //first in, last out

public:

    //Constructor
    Stack()
    {
        this->next = nullptr; //The newest node always pointing to nothing
    }

    //Checks whether the stack is empty or not (Returns true if it is empty. False otherwise)
    //Time Complexity: O(1) because there is only one command
    bool isEmpty(){return first == nullptr;}

    //Adds a new node with data x to the top of the stack
    //Time Complexity: O(n) because the loop iterates at least n times
    void push(int x){

        //Creates a new node with data x
        Stack* newStack = new Stack();
        newStack->data = x;

        //Checks  whether the stack is empty or not
        if (isEmpty()){

            first = newStack; //makes the first node equal to the new node
            //Since there is only one node, then the first node is the last node
            last = first;

            cout << x << " was pushed!\n";

            return; //Leaves function
        }

        Stack* temp = first; //Temporary node to hold the first node

        //Goes through the stack until it reaches the end
        while (temp->next != nullptr)
            temp = temp->next; //Goes to the next node

        //Makes the new node into the last node
        temp->next = newStack;
        last = temp->next;

        cout << x << " was pushed!\n";
    }

    //Removes the last element pushed into the stack
    //Time Complexity: O(n) because the loop iterates at least n times
    int pop(){

        int removed; //variable stores popped data

        //Checks whether the stack is empty or not
        if (isEmpty()){

            cout << "There are no elements to be popped!\n";
        }

        //Checks if the first node is the only node
        else if (first->next == nullptr){

            cout << first->data << " was removed.\n";

            removed = first->data;

            //If the first node was the only node, and it points to nothing
            //Then the last node should point to nothing as well
            first = nullptr;
            last = nullptr;

            return removed; //return the removed data
        }

        Stack* temp = first; //Creates temporary node to store the first node
        removed = last->data;

        //Goes through the stack until it reaches the node before the last
        while (temp->next != last)
            temp = temp->next; //goes to the next node

        //Since temp is the node before the last, then the last node should point to nothing
        //and temp should be the new last node
        temp->next = nullptr;
        last = temp;

        return removed; //return the removed data
    }

    //Returns the data of the last node in the stack, or the the top of the stack
    //Time Complexity: O(1) because there are a constant amount of instructions
    int top(){

        //Checks if the stack is empty
        if (isEmpty()){

            cout << "The stack is empty!\n";

            return 0; //Returns 0 or nothing if the stack is empty
        }

        //If the stack is not empty, then the data of the last node will be returned
        return last->data;
    }

    //Returns the size of the Stack
    //Time Complexity: O(n) because the loop iterates at least n times
    int Size(){

        //If the stack is empty, then the size is zero (returns 0)
        if (isEmpty())
            return 0;

        Stack* temp = first; //temporary node to hold the first node
        int count = 0; //counter for the size

        //Goes through the Stack and counts how many nodes are there
        while (temp != nullptr)
        {
            temp = temp->next; //Goes to next node
            count++; //increments the counter
        }

        return count; //Returns counter (the size of the Stack)
    }

           /*Print function*/
    void print(){

        if (isEmpty()){
            cout << "Linked list is empty!\n";
            return;
        }

        Stack* temp = first;

        while (temp != nullptr){

            if (temp->next == nullptr)
                cout << temp->data << endl;
            else
                cout << temp->data << " -->";

            temp = temp->next;
        }
    }

private:

    Stack* first = nullptr; //Bottom node
    Stack* last = nullptr; //Top node
    Stack* next;
    int data;
};

class Queue{ //first in, first out
public:

    //Constructor
    Queue()
    {
        this->next = nullptr; //Newest pointer always points to nothing
    }

    //Checks whether the stack is empty or not (Returns true if it is empty. False otherwise)
    //Time Complexity: O(1) because there is only one command
    bool isEmpty(){return first == nullptr;}

    //Pushes a new node with data x to the end of the Queue
    //Time Complexity: O(n) because the loop iterates at least n times
    void enqueue(int x){

        Queue* newQ = new Queue(); //Creates new node
        newQ->data = x; //new node has data equal to x

        //Checks if the queue is empty
        if (isEmpty()){

            first = newQ; //makes the first node equal to the new node
            //Since there is only one node, then the first node is the last node
            last = first;

            cout << x << " Was enqueued!\n";

            return; //Leaves the function
        }

        Queue* temp = first; //Temporary node to hold the first node

        //Goes through the queue until it reaches the last node
        while (temp->next != nullptr)
            temp = temp->next; //Goes to the next node

        //Makes the new node into the last node
        temp->next = newQ;
        last = temp;

        cout << x << " Was enqueued!\n";
    }

    //Removes the first node
    //Time Complexity: O(1) because it has a constant amount of instructions
    int dequeue(){

            int removed; //Variable to store removed data
            //Checks if the queue is empty
            if (isEmpty())
                cout << "The queue is empty. It cannot be dequeued." << endl;

            //Checks if the first node is the only node
            //In that case, the first node will point to nothing
            else if (first->next == nullptr){

                cout << first->data << " Was dequeued.\n";

                removed = first->data;

                first = nullptr; //First node is pointing to nothing

                return removed; //returns removed data
            }

            //The case where the first node is not the only node
            //Then the node after the first node will be the new first node
            else{
                cout << first->data << " Was dequeued.\n";

                removed = first->data;

                first = first->next;

                return removed; //returns removed data
            }
    }

    //Returns the data of the first node
    //Time Complexity: O(1) because it has a constant amount of instructions
    int top(){

        //Checks whether the queue is empty or not
        if (isEmpty()){

            cout << "ERROR: queue is EMPTY!" << endl;

            return NULL; //Returns nothing if the queue is empty
        }

        //The case where the queue is not empty.
        //Returns the data of the first node
        return first->data;
    }

    //Returns the size of the queue
    //Time Complexity: O(n) because the loop iterates at least n times
    int Size(){

        //Checks if the queue is empty. (The size is 0 if the queue is empty, so it returns 0)
        if (isEmpty())
            return 0;

        Queue* temp = first; //Temporary node to hold the first node
        int count = 0; //counter for the size

        //Goes through the queue to count the size
        while (temp != nullptr){

            temp = temp->next; //Goes to the next node

            count++;//increments counter
        }

        //Returns the counter (the size)
        return count;
    }

           /*Print function*/
    void print(){

        if (isEmpty()){
            cout << "Linked list is empty!\n";
            return;
        }

        Queue* temp = first;

        while (temp != nullptr){

            if (temp->next == nullptr)
                cout << temp->data << endl;
            else
                cout << temp->data << " -->";

            temp = temp->next;
        }
    }

private:

    Queue* first = nullptr; //First node in the queue
    Queue* last = nullptr; //Last node in the queue
    Queue* next;
    int data;
};

int main(){

    /*Linked List test*/
    cout << "Linked list test:\n";

    LinkedList L;

    L.add(1);
    L.add(2);
    L.add(3);

    L.print();

    cout << "Does the list have 2 as a data? The answer is: ";

    if (L.search(2)) cout << "True\n";
    else cout << "False\n";

    cout << "The size of the list is: " << L.Size() << endl;

    L.Remove(2);

    L.print();

    /*Stack test*/
    cout << "Stack test:\n";

    Stack S;

    S.push(1);
    S.push(2);
    S.push(3);

    S.print();

    cout << "The top of the stack is: " << S.top() << endl;
    cout << "The size of the list is: " << S.Size() << endl;

    S.pop();

    S.print();

    /*Queue test*/
    cout << "Queue test:\n";

    Queue Q;

    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);

    Q.print();

    cout << "The top of the stack is: " << Q.top() << endl;
    cout << "The size of the list is: " << Q.Size() << endl;

    Q.dequeue();

    Q.print();

    return 0;
}
