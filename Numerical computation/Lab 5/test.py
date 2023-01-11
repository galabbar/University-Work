from scipy import optimize

def f(x):
    return (x**2 - 1)

    
print(optimize.bisect(f, 0, 2))
print(optimize.bisect(f, -2, 0))
