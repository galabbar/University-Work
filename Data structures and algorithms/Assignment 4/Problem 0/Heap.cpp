//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Heap.cpp

//Suppose that the size of the heap is n
#include <iostream>
#include <cmath>
using namespace std;

//Swap function for heapify
void Swap(int& x, int& y){

    int temp = x;
    x = y;
    y = temp;
}

//Power function for finding the minimum
int power(int base, int pwr){

    int result = 1;

    for(int i = 0; i < pwr; i++)
        result *= base;

    return result;
}

//Heap Data structure
class Heap{

public:

    //Heap Constructor
    Heap()
    {
        //Sets all the heap array elements to zero
        for (int i = 0; i < 100; i++)
            heapArr[i] = 0;

        //Heap size counter. Starts at -1, and it is incremented each time a new element is added
        Last_inserted = -1;
    }

    //Inserts elements into the heap
    //Time Complexity: O(log(n)) because the heap is traversed by jumping in powers of 2
    void Insert(int data){

        //The case where the heap has reached its capacity
        if (Last_inserted == 99){

            cout << "The heap has reached its capacity!\n";
            return;
        }

        //Checks if the Last_inserted is -1 (meaning the heap is empty)
        if (Last_inserted == -1){

            Last_inserted++; //increments Last_inserted by 1
            heapArr[Last_inserted] = data; //Sets the first element of the heap as the user input (data)

            cout << data <<" Has been inserted to the heap!\n";

            return; //Leaves function
        }

        //The case where the heap has not reached its capacity, and is not empty

        Last_inserted++; //Last_inserted is incremented by 1
        heapArr[Last_inserted] = data; //Sets the first element of the heap as the user input (data)
        cout << data <<" Has been inserted to the heap!\n";

        int i = Last_inserted; //i is the size of the heap, and it will be used to traverse the heap

        //Heapifies the heap after inserting data.
        //Checks if the newly inserted element is larger than its parent. If it is, they swap. Otherwise, the heap is heapified
        while (i >= 0){

            //checks if the newly inserted element is larger than its parent
            if (heapArr[i] > heapArr[i/2]){

                //If that's the case, then they swap
                Swap(heapArr[i], heapArr[i/2]);
                i /= 2; //i is halved
            }

            //if the newly inserted element is not larger than its parent, then the program leaves the loop
            else
                break;
        }
    }

    //Removes an the largest element from the heap
    //Time Complexity: O(log(n)) because the heap is traversed by jumping in powers of 2
    int Delete(){

        //Checks if the heap is empty
        if (Last_inserted == -1){

            cout << "The heap is empty!\n";
            return 0;
        }

        //Checks if there is only one element in the heap
        if (Last_inserted == 0){

            Last_inserted--; //decrement Last_inserted by 1
            cout << heapArr[0] << " Has been removed.\n";
            return heapArr[0]; //returns the removed element
        }

        cout << heapArr[0] << " Has been removed.\n";

        int i = 0; //index i starts at 0
        int Removed = heapArr[0]; //variable to store the removed element

        /////////////Process of heapify//////////////
        //Determines whether the first child is greater than the 2nd child
        //The case where the first child is greater than the second child
        if (heapArr[1] > heapArr[2]){

            heapArr[i] = heapArr[1]; //The root of the heap is now equal to the first child
            i = 1; //index is changed to the first child
        }
        //The case where the first child is less than the second child
        else{

            heapArr[i] = heapArr[2]; //The root of the heap is now equal to the second child
            i = 2; //index is changed to the second child
        }

        //Heapifies the heap past the first or second child
        while (i <= Last_inserted){

            //Determines whether the first child is greater than the 2nd child
            //The case where the first child is less than the second child
            if (heapArr[2*i] < heapArr[2*i + 1]){

                heapArr[i] = heapArr[2*i + 1]; //The root of the heap is now equal to the second child
                i = 2*i + 1; //index is changed to the second child
            }

            //The case where the first child is greater than the second child
            else{

                heapArr[i] = heapArr[2*i]; //The root of the heap is now equal to the first child
                i = 2*i; //index is changed to the first child
            }
        }

        Last_inserted--; //Decrements the heap size after removing the the root and heapifying the array

        return Removed; //Returns the removed element
    }

    //Displays the heap in array form
    //Time Complexity: O(n) because the heap size is variable
    void display(){

        //Checks if the heap is empty
        if (Last_inserted == -1){

            cout << "The heap is empty!\n";
            return;
        }

        //Goes through the heap and prints its contents
        for (int i = 0; i <= Last_inserted; i++)
            cout << heapArr[i] << " "; //Prints the heap element

        cout << endl;
    }

    //Finds the minimum value in the heap and returns it
    //Time Complexity: O(log(n)) because n is variable
    int getMin(){

        int Log_size = (int)log(Last_inserted); //Log_size takes only the integer part of log(Last_inserted)
        int Min = heapArr[Last_inserted]; //Min is initialised

        //Goes through the lower parts of the heap and finds the minimum value
        for (int i = Last_inserted; i >= Last_inserted - power(2,Log_size); i--)

            //Checks if the heap element of index i is less than Min.
            if (heapArr[i] < Min)
                Min = heapArr[i];

        return Min; //Returns Min
    }

    //Returns the Maximum element of the heap
    //Time Complexity: O(1) since there is only one instruction
    int getMax(){

        //Returns the root of the heap
        return heapArr[0];
    }

    //Returns the size of the heap
    //Time Complexity: O(1) Since there is one instruction
    int Size(){

        //Returns Last_inserted + 1 since the first heap index is 1
        return Last_inserted + 1;
    }

    //Checks if the heap is empty
    //Time Complexity: O(1) Since there is one instruction
    bool isEmpty(){

        //Checks if Last_inserted is -1. If it is, then it returns True. Otherwise, returns False.
        return Last_inserted == -1;
    }

private: //Encapsulated members

    int heapArr[100]; //Main heap array
    int Last_inserted; //Counter to keep track of the size of the heap
};

//Beginning of main
int main(){

    Heap h;

    cout << "Is the heap empty? The answer is: ";
    if (h.isEmpty())
        cout << "True!\n";
    else
        cout << "False!\n";

    h.Insert(5);
    h.Insert(33);
    h.Insert(100000);
    h.Insert(12);
    h.Insert(106);
    h.Insert(394);
    h.Insert(507);

    h.display();

    h.Delete();

    h.display();

    h.Insert(942);

    h.display();

    cout << "The largest element is: " << h.getMax() << " and the smallest element is: " << h.getMin() << endl;
    cout << "The size is: " << h.Size() << endl;

    cout << "Is the heap empty? The answer is: ";
    if (h.isEmpty())
        cout << "True!\n";
    else
        cout << "False!\n";

    return 0;
}
//End of main
