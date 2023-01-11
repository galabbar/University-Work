#Name: Ghazi Najeeb AlAbbar
#ID: 2181148914
#Assignment 5
#Pascal.py

class Solution(object):
    #Finds the pascal triangle for the size of the input
    #Let n be the size of the array
    #Time Complexity: O(n^2) since it goes through each list's inner list in an increasing size
    #Space Complexity: O(n^2) Since the list is of size n, and the inner list's sizes go from n, n-1, n-2, ... , 1
    def PascalsTriangle(numRows):

        Res = [] #The resultant list

        #Checks if the size is greater than zero
        if numRows > 0:

            #Appends n empty lists in the result list
            for i in range(numRows):
                Res.append([])

            #Initialises the first list
            Res[0].append(1)

            idx = 1

            #Initialises the rest of the list
            for i in range(1, numRows):

                j = 0
                Res[idx].append(1)
                while True:

                    if j == idx - 1:
                        Res[idx].append(1)
                        break

                    else:
                        Res[idx].append(0)

                    j += 1
                    
                
                idx += 1

            idx = 2

            #Completes the triangle by using the previous list's contents 
            for i in range(2, numRows):

                j = 0
                curr = 1

                while j < idx - 1:

                    Res[i][curr] = Res[i - 1][j] + Res[i - 1][j + 1]

                    j += 1
                    curr += 1

                idx += 1
        
        return Res