#include <iostream>
using namespace std;

void Merge(int arr[], int Start, int Mid, int End){

    int Len_one = Mid - Start + 1, Len_two = End - Mid;

    int* Arr1 = new int [Len_one];
    int* Arr2 = new int [Len_two];

    for (int i = 0; i < Len_one; i++){

        Arr1[i] = arr[Start + i];
    }

    for (int i = 0; i < Len_two; i++){

        Arr2[i] = arr[Mid + 1 + i];
    }

    int idx_one = 0, idx_two = 0, idx = Start;
    while (idx_one < Len_one && idx_two < Len_two){

        if (Arr1[idx_one] < Arr2[idx_two]){

            arr[idx] = Arr1[idx_one];
            idx_one++;
        }

        else{

            arr[idx] = Arr2[idx_two];
            idx_two++;
        }

        idx++;
    }

    while (idx_one < Len_one){

        arr[idx] = Arr1[idx_one];

        idx_one++;
        idx++;
    }

    while (idx_two < Len_two){

        arr[idx] = Arr2[idx_two];

        idx_two++;
        idx++;
    }
}

void mergeSort_Helper(int arr[], int Start, int End){

    if (Start >= End)
        return;

    int Mid = (End + Start) / 2;

    mergeSort_Helper(arr, Start, Mid);
    mergeSort_Helper(arr, Mid + 1, End);
    Merge(arr, Start, Mid, End);
}

bool isSorted(int arr[], int size){

    for (int i = 0; i < size - 1; i++){

        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

void MergeSort(int arr[], int Size){

    if (isSorted(arr, Size))
        return;

    mergeSort_Helper(arr, 0, Size);
}

/**************** Utility Functions **************/
void printArr(int arr[], int Size){

    for (int i = 0; i < Size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void fill(int arr[], int size){

    for (int i = 0; i < size; i++)
        cin >> arr[i]
}
/************************************************/

int main(){

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++){

        int size, *arr;
        
        cin >> size;

        arr = new int [size];
        fill(arr, size);

        MergeSort(arr, Size);

        printArr(arr, size);
    }

    return 0;
}