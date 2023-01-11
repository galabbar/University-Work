//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-3.cpp

//Let n be the size of the array
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

void Swap(int& x, int& y){

    int temp = x;
    x = y;
    y = temp;
}

int power(int base, int pwr){

    int result = 1;

    for(int i = 0; i < pwr; i++)
        result *= base;

    return result;
}

class Heap{

public:

    Heap()
    {
        for (int i = 0; i < 100; i++)
            heapArr[i] = 0;

        Last_inserted = -1;
    }

    void Insert(int data){

        if (Last_inserted == 99){

            cout << "The heap has reached its capacity!\n";
            return;
        }

        if (Last_inserted == -1){

            Last_inserted++;
            heapArr[Last_inserted] = data;

            //cout << data <<" Has been inserted to the heap!\n";

            return;
        }

        Last_inserted++;
        heapArr[Last_inserted] = data;
        //cout << data <<" Has been inserted to the heap!\n";

        int i = Last_inserted;

        while (i >= 0){

            if (heapArr[i] > heapArr[i/2]){

                Swap(heapArr[i], heapArr[i/2]);
                i /= 2;
            }

            else
                break;
        }
    }

    int Delete(){

        if (Last_inserted == -1){

            //cout << "The heap is empty!\n";
            return 0;
        }

        if (Last_inserted == 0){

            Last_inserted--;
            //cout << heapArr[0] << " Has been removed.\n";
            return heapArr[0];
        }

        //cout << heapArr[0] << " Has been removed.\n";

        int i = 0;
        int Removed_Data = heapArr[0];

        if (heapArr[1] > heapArr[2]){

            heapArr[i] = heapArr[1];
            i = 1;
        }
        else{

            heapArr[i] = heapArr[2];
            i = 2;
        }

        while (i <= Last_inserted){

            if (heapArr[2*i] < heapArr[2*i + 1]){

                heapArr[i] = heapArr[2*i + 1];
                i = 2*i + 1;
            }

            else{

                heapArr[i] = heapArr[2*i];
                i = 2*i;
            }
        }

        Last_inserted--;

        return Removed_Data;
    }

    void display(){

        if (Last_inserted == -1){

            cout << "The heap is empty!\n";
            return;
        }

        for (int i = 0; i <= Last_inserted; i++)
            cout << heapArr[i] << " ";

        cout << endl;
    }

    int getMin(){

        int Log_size = (int)log(Last_inserted);
        int Min = heapArr[Last_inserted];

        for (int i = Last_inserted; i >= Last_inserted - power(2,Log_size); i--)
            if (heapArr[i] < Min)
                Min = heapArr[i];

        return Min;
    }

    int getMax(){

        if (Last_inserted == -1){

            cout << "The list is Empty!";
        }
        else
            return heapArr[0];
    }

    int Size(){ return Last_inserted + 1;}

    bool isEmpty(){ return Last_inserted == -1;}

private:

    int heapArr[100];
    int Last_inserted;
};


//Time Complexity: O(nlog(n)) since heap insert and delete were used inside a loop that iterated n times
void HeapSort(int arr[], int size){

    //Declare a heap to sort the array
    Heap H;
    //Declare a stack to use its FILO feature
    stack<int> S;

    //Insert all the array elements in the heap
    for (int i = 0; i < size; i++)
        H.Insert(arr[i]);

    //insert all heap elements in the stack whilst emptying the heap
    while (!H.isEmpty())
        S.push(H.Delete());

    //Insert all stack elements into the array
    for (int i = 0; i < size; i++){

        arr[i] = S.top();
        S.pop();
    }
}

void Display(int arr[], int Size){

    for (int i = 0; i < Size; i++)
        cout << arr[i] << " ";

    cout << endl;
}


int main(){


    int arr[5] = {3, 1, 5, 2, 4};

    cout << "The array before being sorted: ";
    Display(arr, 5);

    cout << "\n\n The array after being sorted: " ;
    HeapSort(arr, 5);
    Display(arr, 5);

    return 0;
}
