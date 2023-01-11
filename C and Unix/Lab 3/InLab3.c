//Student: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//In Lab 3


/*********************************************/
/*  This program enters lines of characters  */
/*  and prints the number of characters in   */
/*  each line.  The total number of lines,   */
/*  total number of characters and average   */
/*    number of characters per line are      */
/*   printed before the program terminates   */
/*********************************************/

#include <stdio.h>

/*********************************************/
/*  Function to count and return the number  */
/*    of characters entered in the line      */
/*********************************************/

int countChars ()
{
    char ch;
    int ctr = 0; //new
    printf("\nEnter your line of characters:  ");
    scanf(" %c", &ch);
    while (ch != '\n')
    {
        ctr++;
        scanf("%c", &ch); //new
    }
    return ctr;
}

/*********************************************/
/*                Main Function              */
/*********************************************/

int main()
{
    char choice, dummy;
    int lines = 0; //new
    int sumchars = 0; //new

    /***    Ask the user if they want to enter a line   **/
    printf("Would you like to enter a line of characters? (y/n)  ");
    scanf(" %c", &choice);

    /***  Loop to enter lines and count characters and lines ***/
    while(choice == 'y' || choice == 'Y') //new
    {
        int num = countChars();  // Function call to return number of chars
        printf("\nThe number of characters in the line = %d\n", num); //print #chars //new
        sumchars += num;  // add number of characters

        printf("Would you like to enter a line of characters? (y/n)  "); //new
    	scanf(" %c", &choice); //new

    	lines++; //new
    }

    /*** print information totals and averages ***/
    if (lines)
    {
        float avg = (float) sumchars/lines;
        printf("\nThe total number of characters entered is:  %d\n", sumchars);
        printf("The total number of lines entered is:  %d\n", lines);
        printf("The average number of characters per line is:  %.2f\n",avg);
    }
    else
        printf("No lines were entered\n");

    return 0;
}
