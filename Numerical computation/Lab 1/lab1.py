#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

def mirror(x):

    Result = 0;
    i = 0;

    while i < 3:

        Result *= 10;
        Result += x%10;

        x = x//10;

        i += 1;
    

    return int(Result);

#Beginning of main
def main():

    User_Input = int(input("Enter a number between 100 and 999: "));

    if User_Input < 100 or User_Input > 999:
        print("Not composed of 3 digits!");
        return 0;

    print("The sum of ", User_Input, " and its mirror is: ", User_Input + mirror(User_Input));
    print("The product of ", User_Input, " and its mirror is: ", User_Input * mirror(User_Input));

#End of main

#Calling main
main();