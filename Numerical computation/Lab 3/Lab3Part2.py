#Name: Ghazi Najeeb AL-Abbar
#ID: 2181148914

#Beginning of main
def main():

    Polynomial = input("Please enter the coefficients in reverse order: ").split();
    Polynomial = list(map(float, Polynomial));

    Var = float(input("Please enter the value of the variable: "));

    Result = 0;
    Length = len(Polynomial);
    i = -1;

    while i >= -(Length - 1):
        
        Result *= Var;
        Result += Polynomial[i] * Var;

        i -= 1;
    
    Result += Polynomial[i];

    print("The value of the polynomial at ", Var, " is ", round(Result, 2));

#End of main

#Calling main
main();