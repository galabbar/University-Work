//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-3.cpp

//A Stack class implemented using two queues from the STL
//Assume that n is the number of elements in the queue

#include <iostream>
#include <queue>
using namespace std;

class Stack{

public:

    //Constructor
    Stack(){/*Empty*/}

    //Returns true if the first queue is empty. False otherwise
    //Time Complexity: O(1) since there is a constant number of commands
    bool isEmpty(){ return Q1.empty();}

    //Stack push implemented using two queues
    //Time Complexity: O(n) because both loops are iterated n times
    void push(int x){

        //Goes through the first queue and emptys it it into the second queue
        while (!Q1.empty()){

            Q2.push(Q1.front());
            Q1.pop();
        }

        //Pushes the data x into the first queue
        //So it can resemble the top element of the stack
        Q1.push(x);

        cout << x << " Was pushed!\n";

        //Pushes everything from the second queue into the first in order
        while (!Q2.empty()){

            Q1.push(Q2.front());
            Q2.pop();
        }
    }

    //Stack pop implemented using queues
    //Time Complexity: O(1), since there is a constant number of commands
    int pop(){

        if (isEmpty()) //Checks if the queue is empty
            cout << "Stack is Empty!\n";

        //The case where it is not empty
        else{
            int removed = Q1.front(); //variable to store the queue top

            cout << Q1.front() << " Was popped!\n";

            Q1.pop();

            return removed; //returns the removed top
        }
    }

    //Stack size implemented using two queues
    //Time Complexity: O(n), because both loops are iterated n times
    int Size(){

        int count = 0; //counter to check how many elements in the queue

        //Goes through the queue and counts each element while emptying the first queue into the second
        while (!Q1.empty()){

            Q2.push(Q1.front());

            Q1.pop();

            count++;
        }

        //Returning everything from the second queue into the first in order
        while (!Q2.empty()){

            Q1.push(Q2.front());

            Q2.pop();
        }

        return count; //returns counter
    }

    //Returns the top of the stack
    //Time Complexity: O(1) since there is only one command
    int top(){ return Q1.front();}

       /*Print function*/
    void print(){

        while (!Q1.empty()){

            Q2.push(Q1.front());
            cout << Q1.front() << "\t";
            Q1.pop();
        }

        cout << " <--  first\n";

        while (!Q2.empty()){

            Q1.push(Q2.front());
            Q2.pop();
        }

    }

private:
    //STL queue
    queue<int> Q1, Q2;
};

int main(){

    Stack S;

    S.push(1);
    S.push(2);
    S.push(3);

    S.print();

    cout << "The size of the stack is: " << S.Size() << endl;
    cout << "The top of the stack is: " << S.top() << endl;

    S.pop();

    S.print();

    return 0;
}
