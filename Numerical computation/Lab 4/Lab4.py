#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914
import math

#Beginning of main
def main():

    i = 3;
    
    print ("No. of Sides","Pi Approximation", "\tPercent Relative error \n", sep = '\t');
    while True:

        Pi_Approx = ( i * (2 * math.sin(math.pi / i)) ) / 2;
        PRE = (abs(math.pi - Pi_Approx) / math.pi) * 100; 

        print(i, Pi_Approx, str(PRE) + " %", sep = "\t\t");

        i += 1;

        if PRE < 2:
            break;

#End of main

#Calling main
main();