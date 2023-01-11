#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

#returns the number of digits in an integer
def DigitsNum(x):
    
    Result = 0
    
    while x != 0:
        
        x = x // 10
        Result += 1
        
    return Result;

#Returns the integer in its mirrored form 
def Mirror(x):
    
    Result = 0;
    Length = DigitsNum(x);
    i = 0;
    
    while i < Length:
        
        Result *= 10;
        Result += x % 10;
        
        x = x // 10;
        
        i += 1;
        
    return Result;

#Sums all the elements of the list in their mirror form
def MirrorSum(L):
    
    Length = len(L);
    Sum = 0;
    i = 0;
    
    while i < Length:
        
        Sum += Mirror(L[i]);
        i += 1;
    
    return Sum;

#Beginning of main
def main():
    
    User_List = input("Please enter numbers to append to the list. To stop, press n: ").split();
    User_List = list(map(int, User_List));
    
    print("The sum of the lists elements mirrored form is: ", MirrorSum(User_List));

#End of main

#Calling main:
main();