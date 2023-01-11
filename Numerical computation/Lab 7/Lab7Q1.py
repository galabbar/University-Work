#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914
#Lab 07
#Lab7Q1.py

import numpy as np

#User input for size of rows and coloumns
rows = int(input("Enter the number of rows: "))
col = int(input("Enter the number of coloumns: "))

Matrix = input("Enter " + str(rows * col) + " elements: ").split();
Matrix = [float(x) for x in Matrix]

#Takes the list that the user entered, then turns it into a row x coloumn size matrix
Matrix = np.array(Matrix).reshape(rows, col);

i = 0
j = 0

#Calculating the sum of the rows
while i < rows:

    sum = 0;
    while j < col:

        sum += Matrix[i][j];
        j += 1;

    print("Sum of row #", i + 1 , " is: ", sum)

    i += 1;
    j = 0

i = 0

#Calculating the sum of the coloumns
while j < col:

    sum = 0;
    while i < rows:

        sum += Matrix[i][j];
        i += 1

    print("Sum of coloumn ", j + 1, " is: ", sum);

    j += 1
    i = 0;
