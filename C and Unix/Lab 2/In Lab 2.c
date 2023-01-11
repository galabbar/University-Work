//Name: Ghazi Najeeb Al-Abbar
//Student ID: 2181148914
//In Lab 2.c

#include <stdio.h>

//Beginning of program
int main(){

    int i = 0, size, sumOdd = 0, sumEven = 0, Multof3 = 0; //Multof3 is to add the sum of all numbers that are a multiple of 3.

    printf("Enter the size of your array (Size must not exceed 20): ");
    scanf("%d", &size);

    int arr[size]; //array declaration after initializing its size

    printf("Enter your array elements: ");
    //Scans the users input and checks whether the index is even, odd or a multiple of 3
    for (i; i< size; i++)
    {
        //scans the user's input
        scanf("%d", arr+i);

        //checks if the index is even. If it is, it is added to sumEven
        if (i%2 == 0)
            sumEven += *(arr + i);

        //checks if the index is odd. If it is, it is added to sumOdd
        if (i%2 != 0)
            sumOdd += *(arr + i);

        //checks if the index is a multiple of 3. If it is, it is added to Multof3
        if (i%3 == 0)
            Multof3 += *(arr + i);
    }

    //Prints out the results
    printf("The sum of the values of even indexed cells: %d\n", sumEven);
    printf("The sum of the values of odd indexed cells: %d\n", sumOdd);
    printf("The sum of the values of cells with indexes that are multiples of 3: %d\n", Multof3);

    return 0;

}//Program end
