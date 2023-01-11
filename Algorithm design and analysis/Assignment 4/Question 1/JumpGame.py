#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914
#Assignment 4
#Question 1

#Uses the array values to determine if we can jump from the first index to the last
# Let n be the size of the array
# Time Complexity: O(n) since the loop could go through the whole list
# space Complexity: O(1) since there is a constant amount of variables 
def canJump(List, Size):

    i = 0;
    
    #Goes through the list and jumps from an index to another until the last one is reached, with the jump length being the value of the current array index
    while True:

        #If the jump lands out of the array of if the current index, which is not the last one, is 0 then return false
        if Size <= 0 or (List[i] == 0 and Size != 1):
            return False

        #If a jump lands on the final index, then return true
        if Size == 1:
            return True
        
        #Determine how much space we have for jumps
        Size -= List[i]
        i += List[i]

#The main function
#Let T be the umber of trials and n be the length of the lists
#Time Complexity: O(Tn) since the algorithm is done T times
#Space Complexity: O(n) since the lists have size n
def main():

    File = open("test2.in", "r")
    Trials = int(File.readline())

    for i in range(Trials):

        Str = File.readline().split()

        Size = int(Str[0])
        List = Str[1:]
        List = [int(x) for x in List]

        print(canJump(List, Size))
#End of main

#Calling main
if __name__ == '__main__':
    main()