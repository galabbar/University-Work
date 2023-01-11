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

#Takes two lists and assigns one to the other
#Let n be the size of the list "src"
#Time Complexity: O(n) since it goes through src
#Space Complexity: O(1) since there are no data structers declared with variable sizes
def assignLists(src, dst):

    #goes through the src and appends whatever is in it to dst
    for i in src:
        dst.append(i)

#Checks if a given list is sorted. Returns true if it is, otherwise, it will return false
#Let n be the size of the list
#Time Complexity: O(n) since it goes through the entire list
#Space Complexity: O(1) since there are no data structers declared with variable sizes
def isSorted(List):

    #Goes through the list and checks if the list is sorted
    for i in range(len(List) - 1):

        #If the current element is greater than the element after it, the the list is not sorted. Return False
        if List[i] > List[i + 1]:
            return False

    #The list is sorted. Return True
    return True
#Computes all permutations of a given list until it lands on a list that is sorted
#Let n be the size of the list
#Time Complexity: O(n!) since it goes through all possible permutations
#Space Complexity: O(1) since there are no data structers declared with variable sizes
def psort_helper(List, idx, Size, Sorted):

    #Checks if the counter is equal to the size of the list
    if idx == Size:

        #Checks if the current list is sorted. If it is, the assign it to "Sorted"
        if isSorted(List):
            assignLists(List, Sorted)

        #Leaves the recursive call
        return   

    #Goes through the list and swaps elements to compute a permutation then un-swaps them to help with finding other permutations
    for i in range(idx, Size):

        List[i], List[idx] = List[idx], List[i]

        psort_helper(List, idx + 1, Size, Sorted)

        List[i], List[idx] = List[idx], List[i]

#Calls psort_helper to sort the given list
#Let n be the size of the list
#Time Complexity: O(n!) since psort_helper was called
#Space Complexity: O(n) since a new list was declared and filled with n elements
def psort(List, Size):

    Sorted_List = []
    psort_helper(List, 0, Size, Sorted_List)

    return Sorted_List

#main program
def main():

    cases = int(input())

    for i in range(cases):

        User_input = input().split()

        Size = int(User_input[0])
        List = User_input[1:]
        List = [int(x) for x in List]

        printList(psort(List, Size))
#End of main

#Calling main
main()