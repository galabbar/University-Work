//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 7
//IDE: QT
//CS142
//letter.cpp

#include <iostream>
#include <string>
#include <sstream>
#include "letter.h"
using namespace std;

//Empty constructor
Letter::Letter()
{
    //Empty
}

//Prints letters that are written in '*'
void Letter::printToScale(string str){

    //Checks if the characters are actually letters. If they are, they will all be capitalised
    if ( toCapital( str ) )
    {
        //Prints out the letters in their '*' form
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < (int)str.size(); j++)
            {
                cout << alphabet[str[j] - 'A'][i] << "";
            }
            cout << endl;
        }
    }

    //The case where there is at least one character that isn't a letter.
    else{

        cout << "The string that you have entered has a character that is not a letter!\n";
        return;
    }
}

//Turns the letters into capital and returns true. Returns false if there is a character that isn't a letter
bool Letter::toCapital(string& str){

    //checks each letter in the string.
    for (int i = 0; i < (int)str.length(); i++)
    {
        //returns false if the character is not a letter
        if (!( ( str[i] >= 'A' && str[i] <= 'Z' ) || ( str[i] >= 'a' && str [i] <= 'z' ) ) )
            return false;

        //Continues with the loop if the letter is already capital
        if ( str[i] >= 'A' && str[i] <= 'Z' )
                   continue;

        //Converts the small letter into capital
        str[i] = char( str[i] - 32 );
    }
    return true;
}

