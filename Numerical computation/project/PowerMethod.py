#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914
#file name: PowerMethod.py

#importing and declaring a variable of type numpy
import numpy as np

#Returns the greatest number in the list
def maxList(list):

    #sets the default max as the first element
    max = list[0]

    #Goes through the list and finds the greatest element
    for i in range(len(list)):

        #Checks if the current element is greater than the max element
        if (list[i] >= max):
            max = list[i]

    #retruns the max
    return max

#Applies the power method to a matrix, and returns its dominant eigen value and eigen vector
def powerMethod(Mat, vec, itr):

    EigenValue = 0

    #Multiplies the array with the resulting vector iterativly
    for i in range(itr):

        vec = np.dot(Mat, vec) #Multiplies the matrix with the vector 
        EigenValue = maxList(vec) #stores the dominant eigen value 
        vec = [round(x/maxList(vec), 2) for x in vec] #Divides every element with the dominant eigen value

    #Returns the eigen vector and the absolute value of the eigen value
    return vec, round(abs(EigenValue), 2)

#Beginning of main
def main():

    N = int(input("Enter the dimension for your square matrix: "))
    itr = int(input("Enter the number of iterations: "))

    Mat = input("Enter " + str(N * N) + " elements for your matrix: ").split()
    Mat = np.array([float(x) for x in Mat]).reshape(N, N)
    Vec = [1] * N

    Vec, EV = powerMethod(Mat, Vec, itr)

    print("The dominant Eigen Value = ", EV, "\nWith Eigen Vector = ", Vec)
#End of main

#Calling main
main()