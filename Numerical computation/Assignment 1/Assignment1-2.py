#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

import math

#Takes a list of coefficients from a quadratic equation and returns the solutions
#poly list = [a, b, c], poly = ax^2 + bx + c
def Solutions(poly):

    #Coefficients 
    a = poly[0];
    b = poly[1];
    c = poly[2];

    #Discriminant
    Discr = (b**2) -(4 * a * c);

    #Checks if the Discriminant is greater than or equal to zero (there is at least one REAL solution) then it returns the solution(s)
    if Discr >= 0:

        Sol1 = (-b + math.sqrt(Discr)) / (2 * a);
        Sol2 = (-b - math.sqrt(Discr)) / (2 * a);

        return Sol1, Sol2;

    #If there are no real solutions, then it returns None.
    return None, None;

#Beginning of main
def main():

    Mat = input("Enter the elements for your 2x2 matrix: ").split();
    Mat = list(map(float, Mat));

    Coeff = [1, -(Mat[0] + Mat[-1]), Mat[0] * Mat[-1] - Mat[1] * Mat[-2]];
    EV1,EV2 = Solutions(Coeff);

    print("The Eigen Values are: ", round(EV1, 3), ", ", round(EV2, 3));
#End of main

#Calling main
main();
