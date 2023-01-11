//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-5.cpp

#include <iostream>
#include <stack>
using namespace std;

//The function takes a string, which is one or more balanced parenthesis, and prints them with a new line for each balanced parenthesis
//Assuming the user entered a balanced parenthesis
//Suppose n = s.length()
//Time Complexity: O(n), because both loops are iterated n times
void split(string s){

    int Parenthesis_Count = 0; //Counter to keep track of the balanced parenthesis
    stack<char> stk; //STL stack declaration to store each character of the string

    //Goes through the string and pushes each character into the stack, beginning with the last character
    for (int i = s.length() - 1; i >= 0; i--)
            stk.push(s[i]); //Pushes the character into the stack

    //Goes through the stack and prints a new line whenever a balanced parenthesis is reached
    for (int i = 0; i < s.length(); i++){

        cout << stk.top(); //Prints an character from the top of the stack

        //If the character is '(', then the counter is incremented
        if (stk.top() == '(')
                Parenthesis_Count++;

        //If the character is ')', then the counter is decremented
        if (stk.top() == ')')
            Parenthesis_Count--;

        //If the counter reaches zero, a new line will be printed
        if (Parenthesis_Count == 0)
            cout << endl;

        stk.pop(); //Removes the top of the stack
    }
}

int main(){

    split("(()()()()()())");
    cout << "\n\n";
    split("()((()))(()()()())");

    return 0;
}
