#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

#Beginning of main
def main():

    Result = 0;

    Polynomial = input("Enter the coefficients (real numbers) and powers (integers) of a polynomial (in decreasing power order): ").split();
    Polynomial = list(map(float, Polynomial));
    Length = len(Polynomial);

    var = float(input("Enter a number: "));

    for i in range(0, Length, 2):

              Result += Polynomial[i] * (var ** Polynomial[i + 1]);

    print("The value of the polynomial at ", var, " is ", round(Result, 2));

#End of main

#Calling main
main();
