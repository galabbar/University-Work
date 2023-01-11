#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

#Finds the peak of a list
#Let n be the size of the list
#Time Complexity: O(log(n)) since the algorithm uses a divide and conquer approach
#Space Complexity: O(n) Because of the stack space
def div_and_conq(List, Size, Start, End, flag, ref):

    #When the size reaches 1, the algorithm checks if the element is the peak 
    if Start >= End:

        #If the flag wasn't set to true, then the search begins
        if flag[0] == False:

            #If the element is at the beginning and is larger than the element after it, then it is a peak
            if Start == 0:
                if List[1] < List[0]:

                    ref[0] = 0
                    flag[0] = True
            
            #If the element is at the end and is larger than the element before it, then it is a peak
            elif End == Size - 1:

                if List[End] > List[End - 1]:

                    ref[0] = End
                    flag[0] = True

            else:
                
                #If the element is larger than the one before it and the one after it, then it is a peak
                if List[Start] > List[Start + 1] and List[Start] > List[Start - 1]:

                    ref[0] = Start
                    flag[0] = True

        return

    #Finds the midway length of the current size
    Mid = (Start + End) // 2

    #Divides the list in halves
    div_and_conq(List, Size, Start, Mid, flag, ref)
    div_and_conq(List, Size, Mid + 1, End, flag, ref)

#Main Function
#Let T be the number of trials and n be the size of the list
#Time Complexity: O(T*n) since the list was mapped from string to int T times
#Space Complexity: O(n) since the list size is variable
def main():

    #Opens the file and reads the number of trials
    File = open("test2.in", "r")
    Trials = int(File.readline())

    #Tests div_and_conq T times
    for i in range(Trials):

        Str = File.readline().split()

        Size = int(Str[0])
        List = Str[1:]
        List = [int(x) for x in List]

        #flag and ref are used as reference variables
        flag = [False]
        ref = [None]

        div_and_conq(List, Size, 0, Size - 1, flag, ref)
        print(ref[0])
#End of main

#Calling main
main()