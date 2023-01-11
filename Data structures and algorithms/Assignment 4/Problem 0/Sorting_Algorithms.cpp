//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Sorting_Algorithms.cpp

//Assume the size of all arrays are n
//Quick sort and merge sort don't work on my pc's compiler, but they work just fine on onlinegdb
#include <iostream>
using namespace std;

//Swap function
void Swap(int& x, int& y){

int temp = x;
x = y;
y = temp;
}

//////////Bubble Sort//////////////////

//Time Complexity: O(n^2) because the size of the array is variable, also there is a nested loop
void bubbleSort(int arr[], int size){

    //Quick test to check if the array is already sorted. It does not affect the overall time complexity

    //Boolean flag to check if the array is sorted
    bool isSorted = false;

    //Goes through the array and checks if it is sorted
    for (int i = 0; i < size - 1; i++){

        //The case where the element of index i is greater than the element of index i + 1
        if (arr[i] > arr[i + 1]){

            isSorted = false; //Boolean flag is set to false
            break; //Breaks the loop
        }

        //The case where the element of index i is less than the element of index i + 1
        else
            isSorted = true; //Boolean flag is true
    }

    //If the flag is true, then the array is sorted and the function ends with time complexity O(n)
    //If not, then the array will continue to be sorted

    if (isSorted){

        cout << "Your array is already sorted!\n";

        return;
    }

    //The case where the array is not sorted
    //Goes through the array and sorts its elements
    for (int i = 0; i < size - 1; i++){

        for (int j = 0; j < size - (i + 1); j++){

            //Checks if array element of index j is greater than the element of index j + 1
            if (arr[j] > arr[j + 1]){

                int temp = arr[j]; //temporary variable holds element of index j

                arr[j] = arr[j + 1]; //assign element of index j + 1 to the element of index j

                arr[j + 1] = temp; //assigns the temporary variable to the element of index j + 1
            }
        }
    }
}
/////////////////////////////////////////////////////////////


///////////////Insert Sort/////////////////////////////////

//Time Complexity: O(n^2) because the size of the array is variable, also there is a nested loop
void insertSort(int arr[], int size){

    //Goes through the array and sorts its elements
    for (int i = 1; i < size; i++){

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
/////////////////////////////////////////////////////////////

//////////////////Merge Sort///////////////////////////////////

//Takes two arrays and merges them into one array in sorted order
//Time Complexity: O(n) Since the size of the array is variable
void Merge(int arr[], int Start, int Middle, int End){

    //Declare two new arrays
    int *subArrOne = new int[Middle - Start + 1], *subArrTwo = new int[End - Middle];

    //Assigns the first array with the elements from the original array from start to middle
    for (int i = 0; i < Middle - Start + 1; i++)
        subArrOne[i] = arr[Start + i];

    //Assigns the second array with the elements from the original array from Middle to End
    for (int i = 0; i < End - Middle; i++)
        subArrTwo[i] = arr[Middle + 1 + i];

    int i = 0, j = 0, Current_index = Start;

    //Goes through the two arrays and merges them in the original array in sorted order
    //Stops if at least one of the arrays has reached its end
    while (i < Middle - Start + 1 && j < End - Middle){

        //Checks if the index i of the first array is less than index j from the second array
        if (subArrOne[i] < subArrTwo[j]){

            arr[Current_index] = subArrOne[i]; //assigns index i of the first array to current index of the original array
            i++; //i is incremented by 1
        }

        //Checks if the index i of the first array is greater than or equal to index j from the second array
        else{
            arr[Current_index] = subArrTwo[j]; //assigns index j of the second array to current index of the original array
               j++; //j is incremented by 1
        }

        Current_index++; //The current index is incremented by 1
    }

    //If the second array has reached its end and the first array did not
    while(i < Middle - Start + 1){

        arr[Current_index] = subArrOne[i]; //assigns index i of the first array to current index of the original array
        i++; //i is incremented by 1
        Current_index++; //The current index is incremented by 1
    }

    //If the first array has reached its end and the second array did not
    while (j < End - Middle){

        arr[Current_index] = subArrTwo[j]; //assigns index j of the second array to current index of the original array
        j++; //j is incremented by 1
        Current_index++; //The current index is incremented by 1
    }
}

//Splits the arrays into two halves recursivley and merges all halves using the merge function
//Time Complexity: O(nlog(n)) Since the recursive movement is dependent on halving the array multiple times
void MergeSort(int arr[], int Start, int End){

    //Stops if the Starting index is greater than or equal to the Stopping index
    if (Start >= End)
        return;

    //Finds the midpoint of the two arrays
    int Middle = (Start + End)/2;

    //Recursivley call itself to split the array and merge them
    MergeSort(arr, Start, Middle);
    MergeSort(arr, Middle + 1, End);

    Merge(arr, Start, Middle, End);
}
/////////////////////////////////////////////////////////////

///////////////////Quick Sort///////////////////////////////

//Sorts an array from a starting point to an ending point
//Time Complexity: O(n) since the array size is variable
int Partition(int arr[], int Start, int End){

    //i is the index of the array
    //j is the index of where the swapping happens, and it determines where the new pivot point might be
    int i, j;
    i = Start; j = Start - 1;

    //Goes through the sub-array and sorts its elements
    for (i; i < End; i++){

           //Checks if current index of the array is less than the last element
           if (arr[i] < arr[End]){

            j++; //increment j by 1
            Swap(arr[i], arr[j]); //swap element of index i with element of index j
        }
    }

    //swap element of index j + 1 with the last element
    Swap(arr[j + 1], arr[End]);

    return j + 1; //Return j + 1
}

//Sorts an array recursivley by splitting it between and sorting after a pivot point
//Time Complexity: O(nlog(n)) Because n is variable
void QuickSort(int arr[], int Start, int End){

    //Stops if the Starting index is greater than or equal to the Stopping index
    if (Start >= End)
        return;

    //Gets the pivot point from the partition function
    int Pivot = Partition(arr, Start, End);

    //Recursivley split the array using the pivot
    QuickSort(arr, Start, Pivot - 1);
    QuickSort(arr, Pivot + 1, End);
}
/////////////////////////////////////////////////////////

//Display function
void Display(int arr[], int Size){

    for (int i = 0; i < Size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

//Beginning of main
int main(){

    int arr1[5] = {6, 7, 4, 8, 1};
    int arr2[5] = {2, 9, 20, 1, 8};
    int arr3[5] = {5, 4, 3, 2, 1};
    int arr4[5] = {5, 4, 3, 2, 1};

    cout << "arr1 before bubble sort: ";
    Display(arr1, 5);

    cout << "arr1 after bubble sort: ";
    bubbleSort(arr1, 5);
    Display(arr1, 5);

    cout << "\n\n";

    cout << "arr2 before insert sort: ";
    Display(arr2, 5);

    cout << "arr2 after insert sort: ";
    insertSort(arr2, 5);
    Display(arr2, 5);

    cout << "\n\n";

    cout << "arr3 before Merge sort: ";
    Display(arr3, 5);

    cout << "arr3 after Merge sort: ";
    MergeSort(arr3,0,5);
    Display(arr3, 5);

    cout << "\n\n";

    cout << "arr4 before Quick sort: ";
    Display(arr4, 5);

    cout << "arr4 after Quick sort: ";
    QuickSort(arr4,0,5);
    Display(arr4, 5);

    return 0;
}
//End of Main
