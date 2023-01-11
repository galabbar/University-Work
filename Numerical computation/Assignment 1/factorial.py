def factorial(x):

    if x == 0:
        return 1;
    
    return x * factorial(x - 1);

for i in range(0, 35):

    print("factorial of ", i, ": ", factorial(i), "\t\tfactorial of ", float(i), ": ", factorial(float(i)));
