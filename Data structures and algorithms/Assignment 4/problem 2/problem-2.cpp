//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-2.cpp

//Assume n is the size of the array
#include <iostream>
using namespace std;

void Merge(int arr[], int Start, int Middle, int End){

    int *subArrOne = new int[Middle - Start + 1], *subArrTwo = new int[End - Middle];

    for (int i = 0; i < Middle - Start + 1; i++)
        subArrOne[i] = arr[Start + i];

    for (int i = 0; i < End - Middle; i++)
        subArrTwo[i] = arr[Middle + 1 + i];

    int i = 0, j = 0, Current_index = Start;
    while (i < Middle - Start + 1 && j < End - Middle){

        if (subArrOne[i] < subArrTwo[j]){

            arr[Current_index] = subArrOne[i];
            i++;
        }
        else{
            arr[Current_index] = subArrTwo[j];
               j++;
        }

        Current_index++;
    }

    while(i < Middle - Start + 1){

        arr[Current_index] = subArrOne[i];
        i++;
        Current_index++;
    }
    while (j < End - Middle){

        arr[Current_index] = subArrTwo[j];
        j++;
        Current_index++;
    }
}

void MergeSort(int arr[], int Start, int End){

    if (Start >= End)
        return;

    int Middle = (Start + End)/2;

    MergeSort(arr, Start, Middle);
    MergeSort(arr, Middle + 1, End);
    Merge(arr, Start, Middle, End);
}

//Time Complexity: O(nlog(n)) Since merge sort is used
int KthSmallest(int arr[], int size, int k){

    //Checks if k is larger than the array size
    if (k > size){

        cout << k << "is larger than the array size!\n";
        return 0;
    }

    //Declare a new array so the original array stays the way it is
    int *newArr = new int [size];

    //Assign the original array to the old array
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];

    MergeSort(newArr, 0, size); //Use merge sort on the new array

    return newArr[k - 1]; //Return element k - 1 from the new array
}

void Display(int arr[], int Size){

    for (int i = 0; i < Size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

//Beginning of main
int main(){

    int arr[10] = {99, 104, 1000, 10, 303, 70, 195, 603, 817, 1023};

    Display(arr, 10);

    cout << "\nThe 3rd smallest element in the array is: " << KthSmallest(arr, 10, 7);

    return 0;
}
//End of main
