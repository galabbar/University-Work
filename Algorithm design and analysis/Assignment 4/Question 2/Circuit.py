#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914
#Assignment 4
#Question 2

# Given two lists, one is the amount of gas and the other is the amount of gas used. This algorithm determines if there is a circular from a certain index
# Let n be the size of the list
# Time Complexity: O(n) since the loops, at most, go through the whole list
# Space Complexity: O(1) since the variable declared are a constant amount
def canCompleteCircuit(Gas, Cost, Size):

    i = 0
    tank = 0

    #Finds an index whose next gas station is close enough such that the gas tank won't be empty halfway there
    #If there isn't, the the function returns -1
    while i < Size:

        #Checks if the gas station is close enough or not.
        #Continues looping if the ient index is not the one, otherwise it breaks.
        if Gas[i] - Cost[i] < 0:
            i += 1
        else:
            break
    
    #The case where there is such index
    if Gas[i] - Cost[i] >= 0:

        idx = i #Holds the chosen index
        stationCounter = 0 #counts the number of stations visited and also for the algorithm to not terminate from the beginning

        tank += Gas[i] #increases the tank with gas from the current station

        #Goes through the list in a circular fashion while using the gas and filling up the tank until a full circle is complete 
        while True:

            #Checks if the list has completed a full circle. If it has, then return the idx
            if i == idx and stationCounter != 0:
                return idx

            #Removes the gas that is used to go from index i to i+1
            tank -= Cost[i]

            #If the tank is depleted of gas, the return -1
            if tank < 0:
                return -1

            #Otherwise, continue to the next gas station and fill the tank
            else:

                if i == Size - 1:
                    i = 0
                else:
                    i += 1

                tank += Gas[i]

            stationCounter += 1

    else:
        return -1

#The main function
#Let T be the umber of trials and n be the length of the lists
#Time Complexity: O(Tn) since the algorithm is done T times
#Space Complexity: O(n) since the lists have size n
def main():

    #Opens the file and reads the input
    File = open("test2.in", "r")
    Trials = int(File.readline())

    for i in range(Trials):

        Size = int(File.readline())

        Gas = File.readline().split()
        Cost = File.readline().split()

        Gas = [int(x) for x in Gas]
        Cost = [int(x) for x in Cost]

        print(canCompleteCircuit(Gas, Cost, Size))
#End of main

#Calling main
if __name__ == '__main__':
    main()