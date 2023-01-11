//myfunctions.c

#include <stdio.h>
#include "myfunctions.h"

//prints all possible permutations of binary numbers of length "length", but removes the ones with any consecutive ones
void printStringsRec(int length,int index,int Arr[])
{
    //checks to see if the array has reached it's last index
	if (index == length)
        {
        int z = 0;
        int isConsecutive = 0; //0 if the string has no consecutive 1s. Otherwise, it's 1.

        //checks if the array has any consecutive 1s
        for (z; z < length; z++)
        {
            if (z + 1 != length)
                if (Arr[z] == 1 && Arr[z + 1] == 1)
                    isConsecutive = 1;
        }

        //The case where there were no consecutive 1s in the array. (The array is printed)
        if (isConsecutive == 0){
            z = 0;
            for (z; z < length; z++)
                printf("%d", Arr[z]);
            printf("  ");
        }
        return;
    }

    //the current index equals 0, and the function is recurred with an incremented index
    Arr[index] = 0;
    printStringsRec(length, index + 1, Arr);

    //the current index equals 1, and the function is recurred with an incremented index
    Arr[index] = 1;
    printStringsRec(length, index + 1, Arr);
}

//initialises the parameters of printstringRec and calls it.
void printStrings(int length)
{
	 int index = 0; //array indexing
    int Arr[length];

    printf("The binary strings of length %d with no consecutive 1s are: ", length);

    printStringsRec(length,index,Arr);

}


