//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-2.cpp

//A Queue class implemented using 4 stacks from the STL
//Assume the n is the number of elements in the stack

#include <iostream>
#include <stack>
using namespace std;

class Queue{

public:

    Queue(){/*Empty*/}

    //Time Complexity: O(1) because it has a constant number of instructions
    bool isEmpty(){ return S1.empty(); }

    //enqueues x into the queue (the first stack)
    //Time Complexity: O(n) because both loops are iterated n - 2 times (worst case scenario)
    void enqueue(int x){

        //Checks if the first stack is empty
        //If it is, x is pushed into the first stack
        if (isEmpty()){

            S1.push(x);

            cout << x << " Was enqueued!\n";

            return; //leaves the function
        }

        //The case where the first stack is not empty

        //Pushes the first element in the queue to the second stack
        if (S2.empty() && !isEmpty()){

            S2.push(S1.top());
            S1.pop();
        }

        //Pushes the second element in the queue to the third stack
        if (S3.empty() && !isEmpty()){

            S3.push(S1.top());
            S1.pop();
        }

        //Fills the fourth stack with the rest of the elements from the first stack
        while (!isEmpty()){

            S4.push(S1.top());
            S1.pop();
        }

        S1.push(x); //Pushes the newest element to the bottom of the first stack (or the beginning of the queue)

        cout << x << " Was enqueued!\n";

        //Empties the 4th stack while filling the first stack
        while (!S4.empty()){

            S1.push(S4.top());
            S4.pop();
        }

        //Puts the second element of the queue as the second top of the first stack
         if (!S3.empty()){

            S1.push(S3.top());
            S3.pop();
        }

        //Puts the first element of the queue as the top of the first stack
        if (!S2.empty()){

            S1.push(S2.top());
            S2.pop();
        }
            }

    //removes the first element from the queue (or the top element from the first stack)
    //Time Complexity: O(1) because there are a constant number of instructions
    int dequeue(){

        //Checks if the queue is empty
        if (isEmpty())
            cout << "The queue is empty!\n";

        //When the queue is not empty
        else{

            int removed = S1.top(); //Stores the top element of the first stack in a variable

            S1.pop(); //Pops the top element

            return removed; //returns the removed element (the recent top)
        }
    }

    //returns the size of the queue
    //Time Complexity: O(1) because there are a constant number of instructions
    int Size(){
        //If the first Stack is empty, the function returns zero
        if (isEmpty()) return 0;

        //Otherwise return the size of the first stack
        return S1.size();
    }

    //returns the first element of the queue (or the last element of the first stack)
    //Time Complexity: O(1) because there are a constant number of instructions
    int top(){ return S1.top(); }

        /*Print function*/
    void print(){

        if (isEmpty()){
            cout << "The queue is empty!\n";
            return;
        }

        while (!isEmpty()){

            cout << S1.top() << "\t";
            S2.push(S1.top());
            S1.pop();
        }

        cout << "\n";

        while (!S2.empty()){
            S1.push(S2.top());
            S2.pop();
        }
    }

private:

    //S1 is used to represent the queue
    //S2, S3, S4 are used to store the elements when a new element is being pushed
    stack<int> S1, S2, S3, S4;

};


int main(){

    Queue Q;

    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);

    Q.print();

    cout << "The size of the queue is: " << Q.Size() << endl;
    cout << "The top of the queue is: " << Q.top() << endl;

    Q.dequeue();

    Q.print();

    return 0;
}
