#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

import math
import random

#Beginning of main
def main():

    #User input list
    # Num_List = input("Enter a list of real numbers: ").split();
    # Num_List = list(map(float, Num_List));

    #Test list
    Num_List = [17.567, 65.654, 6.679, 10.1];

    #List length
    Length = len(Num_List);

    #Initialising the sum to zero so we can add on it
    Sum = 0;

    #Sums up all numbers from the given list
    for i in range(Length):

        Sum += Num_List[i];

    print("The percentages sum up to: ", Sum);

    if Sum != 100:

        print("The percentages don't add up to 100!");
        return;

    #Rounds the numbers and puts them back in their respective index
    for i in range(Length):

        print(Num_List[i], "%" + " is rounded to ", round(Num_List[i]), "%");
        Num_List[i] = round(Num_List[i]);
    
    #Sum is set to zero again to get the sum of the rounded list elements
    Sum = 0;
    for i in range(Length):

        Sum += Num_List[i];
    
    print("The sum after rounding is ", Sum);
    
    #If the list indexes all add up to 100%, then their is no error in the rounded numbers
    if Sum == 100:
        print("There is no rounding error. Their sum adds up to 100!");
    
    #If they add up to more than 100%, then one of the elements must be decremented by one to bring it back to 100%
    elif Sum > 100:
    
        Sum = 0;
        idx = random.randint(0, Length - 1); #an element is picked by random to decrement

        for i in range(Length):

            if i == idx:
                Sum += Num_List[idx] - 1;
            
            else:
                Sum += Num_List[i];
        
        #Prints a message to show that it is a success
        if Sum == 100:

            print("It is back to 100% now. ", Num_List[idx], " was decremented by one as an example");
            return;
    
    #If they add up to less than 100%, then one of the elements must be incremented by one to bring it back to 100%
    else:

        Sum = 0;
        idx = random.randint(0, Length - 1); #an element is picked by random to decrement

        for i in range(Length):

            if i == idx:
                Sum += Num_List[idx] + 1;
            
            else:
                Sum += Num_List[i];
        
        #Prints a message to show that it is a success
        if Sum == 100:

            print("It is back to 100% now. ", Num_List[idx], " was incremented by one as an example");
            return;

#End of main

#Calling main
main();