#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

#Utility function that prints a list
#Let n be the size of the list
#Time Complexity: O(n) since it goes through all of the list
#Space complexity: O(1) since there are no data structers declared with variable sizes
def printList(List):

    #Goes through the list and prints each element
    for i in List:

        print(i, end=' ')

    print("\n")

#Helps sort a section of a list
#Let n be the distance between Start and End
#Time Complexity: O(n) since it goes through the list and sorts a section of it
#Space Complexity: O(n) Since two lists were created
def Merge(List, Start, Mid, End):

    L1_Len = Mid - Start + 1 #Size of the first list
    L2_Len = End - Mid #Size of the second list

    #Two lists were declared with initial sizes corresponding to the sizes above
    L1 = [None] * L1_Len
    L2 = [None] * L2_Len
    
    #Fills up the first list with the elements from the original list from Start to Mid
    for i in range(L1_Len):
        L1[i] = List[Start + i]
    
    #Fills up the second list with the elements from the original list from Mid to End
    for i in range(L2_Len):
        L2[i] = List[Mid + i + 1]
    
    #Indexes for L1, L2, and the original list, respectivly
    L1Idx = 0
    L2Idx = 0
    idx = Start

    #Sorts the a section of the list Beginning from Start to End using the two new lists 
    while L1Idx < L1_Len and L2Idx < L2_Len:

        #Checks if the current L1 element is greater than the current L2 element
        #If it is, then the current index of the original list is equal to the current L2 element and L1's index is incremented
        if L1[L1Idx] > L2[L2Idx]:

            List[idx] = L2[L2Idx]
            L2Idx += 1

        #else, then the current index of the original list is equal to the current L2 element and L2's index is incremented
        else:
            List[idx] = L1[L1Idx]
            L1Idx += 1
        
        #The original list's current index is incremented
        idx += 1

    #The case where L1 has not reached its last index, then the rest of L1 is copied in the original list
    while L1Idx < L1_Len:

        List[idx] = L1[L1Idx]

        L1Idx += 1
        idx += 1

    #The case where L2 has not reached its last index, then the rest of L2 is copied in the original list
    while L2Idx < L2_Len:

        List[idx] = L2[L2Idx]

        L2Idx += 1
        idx += 1

#Sorts a list by dividing the list into smaller lists until the size has been reduced to one element, then sorts each list using the merge function
#Let n be the size of the list
#Time Complexity: O(n*log(n)) since the number of recursions depend on how many times the size can be divided by 2 while calling the merge function each
#                             time the size is greater than 1
#Space Complexity: O(n) Since the merge function has a space complexity of O(n)
def mergeSort(List, Start, End):

    #Leaves the recursive call if the size has reached 1
    if Start >= End:
        return

    #Finds the midpoint of the current sublist
    Mid = (End + Start) // 2
    
    #The function recursively calls itself twice, one for each half of the list
    mergeSort(List, Start, Mid)
    mergeSort(List, Mid + 1, End)

    #Merges the current sublist
    Merge(List, Start, Mid, End)

#main program
def main():

    cases = int(input())

    for i in range(cases):

        User_Input = input().split()

        Size = int(User_Input[0])

        List = User_Input[1:]
        List = [int(x) for x in List]

        mergeSort(List, 0, Size - 1)

        printList(List)
#End of main

#Calling main
main()