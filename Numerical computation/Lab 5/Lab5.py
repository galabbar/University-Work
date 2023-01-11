#Name: Ghazy Najeeb Al-Abbar
#ID: 2181148914

#returns the solution to the function f at x
def F(f, x):

    Result = f[0];
    Length = len(f);

    for i in range(1, Length):

        Result += f[i] * x**i;

    return Result;



#f is a list of coefficients and index is the power. For example, if f(x) = 2x^3 - 3x^2 + 4x - 1, then f is [-1, 4, 3, 2]
#a and b are the brackets, and e is the epsilon
def Bisection(f, a, b, e):

    #if f(a)*f(b) is greater than zero, then the brackets do not contain a root. Prints an error message and returns
    if F(f,a) * F(f,b) > 0:

        print("The given brackets do not contain the solution");
        return;

    #if f(a)*f(b) equals zero, then either a or b is the solution. (perhaps both?) 
    if F(f, a) * F(f, b) == 0:

        if F(f, a) == 0:
            return a;

        else:
            return b;
    
    #Iterator counter
    itr = 0;

    print("iterations", "a", "b", "f(a)", "f(b)", "midpoint", "f(midpoint)", "epsilon = 0.005", sep = "\t\t");

    #Applys the bisection method on the given polynomial. Returns the x value such that f(x) is less than or equal to epsilon
    while True:
        
        #Gets the midpoint between point a and b
        midPoint = (a + b) / 2;

        print(itr + 1, " "*10 , a, " "*3, b, " "*3, F(f, a), " "*3, F(f, b), " "*3, midPoint, " "*9, F(f, midPoint), sep = "\t");

        #if the function at the midpoint is less than or equal to epsilon, then the function returns the midpoint
        if F(f, midPoint) <= e and F(f, midPoint) > 0:
             return midPoint;

        #if the midpoint isn't a possible root, then we make it a bracket.
        #if f(a)*f(midpoint) is less than zero, then the midpoint becomes the new right bracket
        if F(f, a) * F(f, midPoint) < 0:
             b = midPoint;

        #else f(midpoint)*f(b) is less than zero, then the midpoint becomes the new left bracket  
        elif F(f, midPoint) * F(f, b) < 0:
            a = midPoint;
        
        #The iterator is incremented by one
        itr += 1;


#Beginning of main
def main():

    '''
    func = input("Enter the coefficients of the polynomial in ascending order: ").split();
    func = list(map(float, func));

    Left_Bracket = float(input("Enter the left bracket: "));
    Right_Bracket = float(input("Enter the Right bracket: "));

    epsilon = float(input("Enter your epsilon: "));

    Root = Bisection(func, Left_Bracket, Right_Bracket, epsilon);

    print("An approximation of the Solution is ", Root);

    '''

    #Test case
    f = [-12, 0, -9, 0.4];
    root = Bisection(f, 20, 25, 0.005);

    print("\nThe root is approximatley ", root);

#End of main

#Calling main
main();
    