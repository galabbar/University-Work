//Name: Ghazi Najeeb AL-Abbar
//ID: 2181148914
//InLab5.c

#include <stdio.h>
#define SIZE 1000

//Beginning of program
int main(){

	int arr[SIZE], i = 0, j;
	
	//Initialise every element to 1 (it means it is prime)
	for (i; i < SIZE; i++)
		*(arr + i) = 1;
		
	*arr = 0; // Make the first index zero (1 is not prime)
	
	//Goes through the array index after the index 2
	for ( i = 2; i < SIZE; i++ )
	{
		j = i + 1; // equates j to be an incremented i
		
		//Goes through the array and checks whether the number is prime or not
		//Makes the array of index j equals to 0 if it is not prime
		for (j; j < SIZE; j++){
			if (j%i == 0)
				*(arr + j) = 0;
		}
	}
	
	//Print the array indexes with the result of it being prime or not
	for (i = 2; i < SIZE; i++)
		printf("number:%d prime? %d\n", i,*(arr + i));
		
	
	return 0;
}
//Ending of program
