#include <iostream>
using namespace std;

void Merge(int arr[], int Start, int Middle1, int Middle2, int Middle3, int Middle4, int End){

    int Size1 = Middle1 - Start + 1;
    int Size2 = Middle2 - Middle1 + 1;
    int Size3 = Middle3 - Middle2 + 1;
    int Size4 = Middle4 - Middle3 + 1;
    int Size5 = End - Middle4;

    int *SubArr1 = new int [Size1];
    int *SubArr2 = new int [Size2];
    int *SubArr3 = new int [Size3];
    int *SubArr4 = new int [Size4];
    int *SubArr5 = new int [Size5];

    for (int i = 0; i < Size1; i++)
        SubArr1[i] = arr[Size1 + i]

    for (int i = 0; i < Size2; i++)
        SubArr2[i] = arr[Size2 + i];

    for (int i = 0; i < Size3; i++)
        SubArr3[i] = arr[Size3 + i];

    for (int i = 0; i < Size4; i++)
        SubArr4[i] = arr[Size4 + i]

    for (int i = 0; i < Size5; i++)
        SubArr5[i] = arr[Middle4 + i];

    int i = 0, j = 0, k = 0, u = 0, v = 0, current_index = Start;
    while (i < Size1 && j < Size2 && k < Size3 && u < Size4 && v < Size5){

        if (SubArr1[i] < SubArr2[j]){
            if (SubArr1[i] < SubArr3[k])
                if (SubArr1[i] < SubArr4[u])
                    if (SubArr1[i] < SubArr5[v]){

                        arr[current_index] = SubArr1[i];
                        i++
                    }
        }

        else if(SubArr2[j] < SubArr3[k]){
            if (SubArr2[j] < SubArr4[u])
                if (SubArr2[j] < SubArr5[v]){

                    arr[current_index] = SubArr2[j];
                    j++;
                }
        }

        else if (SubArr3[k] < SubArr4[u]){
            if (SubArr3[k] < SubArr5[v]){

                arr[current_index] = SubArr3[k];
                k++;
            }
        }

        else if (SubArr4[u] < SubArr5[v]){

            arr[current_index] = SubArr4[u];
            u++;
        }

        else{

            arr[current_index] = SubArr5[v];
            v++;
        }

        current_index++;

    }

    while (i < Size1 && j < Size2 && k < Size3 && u < Size4){

        if (SubArr1[i] < SubArr2[j]){
            if (SubArr1[i] < SubArr3[k])
                if (SubArr1[i] < SubArr4[u]){

                    arr[current_index] = SubArr1[i];
                    i++;
                }
        }

        else if (SubArr2[j] < SubArr3[k]){
            if (SubArr2[j] < SubArr4[u]){

                arr[current_index] = SubArr2[j];
                j++;
            }
        }

        else if (SubArr3[k] < SubArr4[u]){

            arr[current_index] = SubArr3[k];
            k++;
        }

        else{

            arr[current_index] = SubArr4[u];
            u++;
        }

        current_index++;
    }

    while (i < Size1 && j < Size2 && k < Size3 && v < Size5){

        if (SubArr1[i] < SubArr2[j]){
            if (SubArr1[i] < SubArr3[k])
                if (SubArr1[i] < SubArr5[v]){

                    arr[current_index] = SubArr1[i];
                    i++;
                }
        }

        else if (SubArr2[j] < SubArr3[k]){
            if (SubArr2[j] < SubArr5[v]){

                arr[current_index] = SubArr2[j];
                j++;
            }
        }

        else if (SubArr3[k] < SubArr5[v]){

            arr[current_index] = SubArr3[k];
            k++;
        }

        else{

            arr[current_index] = SubArr5[v];
            v++;
        }
    }

    while (i < Size1 && j < Size2 && v < Size5 && u < Size4){

        if (SubArr1[i] < SubArr2[j]){
            if (SubArr1[i] < SubArr5[v])
                if (SubArr1[i] < SubArr4[u]){

                    arr[current_index] = SubArr1[i];
                    i++;
                }
        }

        else if (SubArr2[j] < SubArr5[v]){
            if (SubArr2[j] < SubArr4[u]){

                arr[current_index] = SubArr2[j];
                j++;
            }
        }

        else if (SubArr5[v] < SubArr4[u]){

            arr[current_index] = SubArr5[v];
            v++;
        }

        else{

            arr[current_index] = SubArr4[u];
            u++;
        }

        current_index++;
    }

    while (i < Size1 && v < Size5 && k < Size3 && u < Size4){

        if (SubArr1[i] < SubArr5[v]){
            if (SubArr1[i] < SubArr3[k])
                if (SubArr1[i] < SubArr4[u]){

                    arr[current_index] = SubArr1[i];
                    i++;
                }
        }

        else if (SubArr5[v] < SubArr3[k]){
            if (SubArr5[v] < SubArr4[u]){

                arr[current_index] = SubArr5[v];
                v++;
            }
        }

        else if (SubArr3[k] < SubArr4[u]){

            arr[current_index] = SubArr3[k];
            k++;
        }

        else{

            arr[current_index] = SubArr4[u];
            u++;
        }

        current_index++;
    }

    while (v < Size5 && j < Size2 && k < Size3 && u < Size4){

        if (SubArr5[v] < SubArr2[j]){
            if (SubArr5[v] < SubArr3[k])
                if (SubArr5[v] < SubArr4[u]){

                    arr[current_index] = SubArr5[v];
                    v++;
                }
        }

        else if (SubArr2[j] < SubArr3[k]){
            if (SubArr2[j] < SubArr4[u]){

                arr[current_index] = SubArr2[j];
                j++;
            }
        }

        else if (SubArr3[k] < SubArr4[u]){

            arr[current_index] = SubArr3[k];
            k++;
        }

        else{

            arr[current_index] = SubArr4[u];
            u++;
        }

        current_index++;
    }

    while (i < Size1 && j < Size2 && k < Size3){

        if (SubArr1[i] < SubArr2[j]){
            if (SubArr1[i] < SubArr3[k]){

                arr[current_index] = SubArr1[i];
                i++;
            }
        }

        else if (SubArr2[j] < SubArr3[k]){

            arr[current_index] = SubArr2[j];
            j++;
        }

        else{

            arr[current_index] = SubArr3[k];
            k++;
        }

        current_index++;
    }

    while (i < Size1 && j < Size2 && u < Size4){

        if (SubArr1[i] < SubArr2[j]){
            if (SubArr1[i] < SubArr4[u]){

                arr[current_index] = SubArr1[i];
                i++;
            }
        }

        else if (SubArr2[j] < SubArr4[u]){

            arr[current_index] = SubArr2[j];
            j++;
        }

        else{

            arr[current_index] = SubArr4[u];
            u++;
        }

        current_index++;
    }

    while (i < Size1 && j < Size2 && v < Size5){

        if (SubArr1[i] < Sub)
    }
    while (i < Size1 && u < Size4 && k < Size3){}
    while (i < Size1 && v < Size5 && k < Size3){}
    while (u < Size4 && j < Size2 && k < Size3){}
    while (v < Size5 && j < Size2 && k < Size3){}
    while (i < Size1 && v < Size5 && u < Size4){}
    while (u < Size4 && v < Size5 && k < Size3){}
    while (v < Size5 && j < Size2 && u < Size4){}

    while (i < Size1 && j < Size2){

        if (SubArr1[i] < SubArr2[j]){

            arr[current_index] = SubArr1[i];
            i++;
        }

        else{

            arr[current_index] = SubArr2[j];
            j++;
        }

        current_index++;
    }
    while (i < Size1 && k < Size3){}
    while (i < Size1 && u < Size4){}
    while (i < Size1 && v < Size5){}
    while (j < Size2 && k < Size3){}
    while (j < Size2 && u < Size4){}
    while (j < Size2 && v < Size5){}
    while (k < Size3 && u < Size4){}
    while (k < Size3 && v < Size5){}
    while (v < Size5 && u < Size4){}

    while (i < Size1){

        arr[current_index] = SubArr1[i];
        i++;
        current_index++;
    }

    while (j < Size2){

        arr[current_index] = SubArr2[j];
        j++;
        current_index++;
    }

    while (k < Size3){

        arr[current_index] = SubArr3[k];
        k++;
        current_index++;
    }

    while (u < Size4){

        arr[current_index] = SubArr4[u];
        u++;
        current_index++;
    }

    while (v < Size5){

        arr[current_index] = SubArr5[v];
        v++;
        current_index++;
    }
}


void MergeSort(int arr[], int Start, int End){

    if (Start >= End)
        return;

    float Mid1 = End / 5;
    float Mid2 = (End / 5) + Mid1;
    float Mid3 = (End / 5) + Mid2;
    float Mid4 = (End / 5) + Mid3;

    MergeSort(arr, Start, Mid1);
    MergeSort(arr, Mid1 + 1, Mid2);
    MergeSort(arr, Mid2 + 1, Mid3);
    MergeSort(arr, Mid3 + 1, Mid4);
    MergeSort(arr, Mid4 + 1, End);

    Merge(arr, Start, Mid1, Mid2, Mid3, Mid4, End);
}
