#Name: Ghazi Najeeb AlAbbar
#ID: 2181148914
#Assignment 5
#JumpGame.py

class Solution(object):
    #Computes the amount of jumps needed to go from the first index to the last using the array index values as the maximum jump length
    #Let n be the size of the array
    #Time Complexity: O(n^2) Since the worst case would be an array full of 1's
    #Space Complexity: O(1) Since the amount of variables declared are constant
    def jump(A):

        Size, Reach, i, j = len(A), 0, 0, 0
        num_of_jumps = 0

        #Goes through the array until the appropriate number of jumps is satsified
        while i < Size - 1:

            #Finds the maximum jump that should be taken
            while j < i + 1:

                Reach = max(Reach, A[j] + j)
                j += 1
            
            i = Reach #Jumps the distance
            num_of_jumps += 1 #increments the number of jumps
        
        return num_of_jumps #Returns the number of jumps needed