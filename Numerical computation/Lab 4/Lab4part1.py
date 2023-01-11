#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914
import math

#Beginning of main
def main():

    n = int(input("Enter how many approximations you would like: "));

    print ("No. of Sides","Pi Approximation", "Percent Relative error", sep = '\t');
    for i in range(3, n):

        Pi_Approx = ( i * (2 * math.sin(math.pi / i)) ) / 2;
        PRE = (abs(math.pi - Pi_Approx) / math.pi) * 100; 

        print(i, Pi_Approx, str(PRE) + "%", sep = "\t");

#End of main

#Calling main
main();

        

        

