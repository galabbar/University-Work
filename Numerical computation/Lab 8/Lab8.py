#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

import numpy as np

n = int(input("Enter N: "))
A = input("Enter "+ str(n*n)+ " elements of matrix A: ").split()
A = [float(x) for x in A]
A = np.array(A).reshape(n, n)

b = input("Enter "+ str(n) + " elements of  vector B: ").split()
b = [float(x) for x in b]
b = np.array(b)

x = np.zeros(n)           #x=[0]*n followed by x=np.array(x)
####### Printing Input:
print("A= ",A, sep='\n')
print("X= ",x)   #currently Zeros
print("b= ",b)
######Start Gauss-Seidel
K = int(input("Enter K, number of iterations: "))

_k_ = 0

while _k_ < K:

    i = 0;
    while i < n:

        j = 0;
        Sum = 0;
        while j < n:
            
            if j != i:
                Sum += A[i][j] * x[j];

            j += 1;

        x[i] = (1 / A[i][i]) * (b[i] - Sum);
        
        i += 1;

    _k_ += 1;

    print("K = ", _k_, ": ", x)