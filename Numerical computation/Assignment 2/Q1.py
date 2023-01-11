#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

import math

def Approx_one(N):
    
    Sum = 0;
    i = 0;

    print("Approximations of pi from the first Approximation:");
    while i <= N:

        Sum += ((-1)**i) / (2 * i + 1);

        i += 1;

        print(4 * Sum);

    return 4 * Sum;

def Approx_Two(N):

    Sum = 0;
    i = 1;

    print("Approximations of pi from the Second Approximation:");
    while i <= N:

        Sum += 1 / (i**2);

        i += 1;

        print(math.sqrt(Sum * 6));
    
    return math.sqrt(Sum * 6);

def Approx_Three(N):

    Sum = 0;
    i = 1;

    print("Approximations of pi from the Third Approximation:");
    while i <= N:

        Sum += 1 / i**4;

        i += 1;

        print(math.sqrt(math.sqrt(90*Sum)))

    return math.sqrt(math.sqrt(90*Sum));

#Beginning of main
def main():

    #N = int(input("Enter the number of trials: "));
    N = 25;

    Pi = math.pi;

    print("Original Pi value: ", Pi);
    print("Approximations:\n")

    Pi_1 = Approx_one(N);
    print("\nPercent Relative Error = ", (abs(Pi_1 - Pi) / Pi) * 100, "%\n");

    Pi_2 = Approx_Two(N);
    print("\nPercent Relative Error = ", (abs(Pi_2 - Pi) / Pi) * 100, "%\n");

    Pi_3 = Approx_Three(N);
    print("\nPercent Relative Error = ", (abs(Pi_3 - Pi) / Pi) * 100, "%\n");
#End of main

#Calling main
main();