#include <stdio.h>

int main(void){

	int x, y, z;
 
	printf("Enter the first side: ");
	scanf("%d", &x);

        printf("Enter your second side: ");
	scanf("%d", &y);
	
	printf("Enter your third side: ");
	scanf("%d", &z);

	int result = (x*x) + (y*y);

	if (result > (z*z)  || result < (z*z) )
		printf("Your triangle is not a right triangle!\n");

	else
		printf("Your triangle is a right triangle!\n");

	return 0;
} 
