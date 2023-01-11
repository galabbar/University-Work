#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

import numpy as np

def f(x):

    return (x + 7) / x;

def JumpSum(list, Start, End, jump, flag):

    Sum = 0;

    if flag:

        for i in range(Start,End):

            if (i % jump == 0):
                Sum += list[i];
    else:

        for i in range(Start, End):

            if (i % jump != 0):
                Sum += list[i];
    
    return Sum;

#Beginning of main
def main():
    lower = int(input("Enter the lower limit: "));
    upper = int(input("Enter the upper limit: "));
    N = int(input("Enter how many intervals you want: "));

    x = np.linspace(lower, upper, N + 1);
    y = [f(x) for x in x];

    h = (upper - lower) / N;

    Integration = ((3*h)/8) * (y[0] + 3*JumpSum(y, 1, N, 3, False) + 2*JumpSum(y, 1, N, 3, True) + y[N]);
    print(round(Integration, 5));
#End of main

#Calling main
main();