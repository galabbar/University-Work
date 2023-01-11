//Name: Ghazi Najeeb Al-abbar
//ID: 2181148914

#include <stdio.h>

int main(){

	int hours, minutes;
	
	printf("Enter a time in 24-hour format: ");
	scanf("%d%*c%d", &hours, &minutes);
	
	printf("The time you entered in military time is: %02d%d\n", hours, minutes);
	
	return 0;  
}
