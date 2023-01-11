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

#Utility function to produce the factorial of a certain integer
#Let n be the distance from N to zero
#Time Complexity: O(n) since it goes through the all the numbers between [N,0] one by one
#Space Complexity: O(1) since there are no data structers declared with variable sizes
def factorial(N):

    if N == 0:
        return 1

    return N * factorial(N - 1)

#Prints all possible permutations of the given list elements
#Let n be the size of the list
#Time Complexity: O(n!) since it goes through all possible permutations
#Space Complexity: O(1) since there are no data structers declared with variable sizes
def printPermutations(List, idx, Size):

    #Prints the list when the counter has reached the size of the list
    if idx == Size:

        printList(List)
        return

    #Goes through the list and swaps elements to compute a permutation then un-swaps them to help with finding other permutations
    for i in range(idx, Size):

        List[i], List[idx] = List[idx], List[i]

        printPermutations(List, idx + 1, Size)

        List[i], List[idx] = List[idx], List[i]

#Main program
def main():

    Cases = int(input())

    for i in range(Cases):

        User_Input = input().split()

        Size = int(User_Input[0])
        List = User_Input[1:]
        List = [int(x) for x in List]

        print(factorial(Size))
        printPermutations(List, 0, Size)
#End of Main

#Calling main
main()