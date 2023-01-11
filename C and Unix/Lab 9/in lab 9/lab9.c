//Name: Ghazoi Najeeb Al-Abbar
//ID: 2181148914
//lab9.c

#include <stdio.h>
#include <ctype.h>

enum Options{ INTEGER = 1, FLOAT, CHARACTER, QUIT};

typedef union useroptions{

	enum Options User_Option;

	int User_int;
	float User_float;
	char User_char;
}User_Options;

int main(){
	
	int i = 0, Sum = 0;
	float Max_float = -1000;
	
	User_Options User_Input[50] = {0};
	
	printf("1.	Enter an integer value\n");
	printf("2.	Enter a float value\n");
	printf("3.	Enter a character\n");
	printf("4.	Quit\n");
	printf("Enter the value of your choice: ");
	scanf("%d", &User_Input[i].User_Option);
	printf("\n");
	
	while (User_Input[i].User_Option != QUIT){
	
		if (User_Input[i].User_Option == INTEGER)
		{
			printf("Enter the integer value: ");
			scanf("%d",&User_Input[i].User_int);
			Sum += User_Input[i].User_int;
		}
		
		if (User_Input[i].User_Option == FLOAT){
			printf("Enter the float value: ");
			scanf("%f",&User_Input[i].User_float);
			
			if (User_Input[i].User_float > Max_float)
				Max_float = User_Input[i].User_float;
		}
		
		if (User_Input[i].User_Option == CHARACTER){
			printf("Enter the character value: ");
			scanf(" %c",&User_Input[i].User_char);
		}
		
		i++;
		
		printf("1.	Enter an integer value\n");
		printf("2.	Enter a float value\n");
		printf("3.	Enter a character\n");
		printf("4.	Quit\n");
		printf("Enter the value of your choice: ");
		scanf("%d", &User_Input[i].User_Option);
		printf("\n");
	}
	
	printf("The largest float value is %f\n", Max_float);
	printf("The average of the integer values is %f\n", Sum / i);
	
	i = 0;
	
	printf("The alphabets entered are: ");
	
	while(User_Input[i].User_Option != QUIT)
	{
		if (isalpha(User_Input[i].User_char))
			printf("%c ", User_Input[i].User_char);
		
		i++;
	}
	
	printf("\n");
	
	return 0;
}
