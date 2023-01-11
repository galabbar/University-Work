//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 6
//CS142
//IDE: QT
//main.cpp

#include <iostream>
#include "cid.h"
using namespace std;

//checks whether the parameter is 12 digits long or not
bool is12digits(long long ID){
    int count = 0;
    while (ID > 0){
        ID /= 10;
        count++;
    }
    if (count == 12)
        return true;
    return false;
}

//returns the digit in the position inputed from the given ID (ID is considered to be 12 digits long)
int digit(long long ID, int position){
    long long x = 10;
    for (int i = 1; i <= 12 - position; i++)
        x *= 10;
    return (ID % x) / (x/10);
}

//Beginning of program
int main()
{
    long long ID;
    while (true){
        cout << "Enter a Civil ID: ";
        cin >> ID;

        //Throws exception if the id is not 12 digits long
        try {
            if (!is12digits(ID))
                throw 1;
        }  catch (...) {
            cout << "Civil ID must be 12 digits!" << endl;
            continue;
        }

        //Throws exception if the civil id doesn't start with 2 or 3
        try {
            if (!(digit(ID,1) == 2 || digit(ID,1) == 3))
                throw 1;

        }  catch (...) {
            cout << "The first digit is invalid!" << endl;
            continue;
        }

        //Throws exception if the year is not before 2020
        try {
            //Checks that the year is before 2020
            if ( digit(ID,1) == 3 && digit(ID,2) >= 2)
                throw 1;
        }  catch (...) {
            cout << "Digits 2 and/or 3 are invalid" << endl;
            continue;
        }

        //Throws an exception if the first digit of a month isn't a one or zero
        try {
            if ( !(digit(ID,4) == 1 || digit(ID,4) == 0))
            throw 1;
        }  catch (...) {
            cout << "Digits 4 and/or 5 are invalid!" << endl;
            continue;
        }

        //Throws an exception if a month is above 12
        try {
            if (!((digit(ID,4) == 1 && (digit(ID,5) == 0 || digit(ID,5) == 1 || digit(ID,5) == 2)) || (digit(ID,5) > 0 && digit(ID,5) <= 9)))
                throw 1;

        }  catch(...){
            cout << "Digits 4 and/or 5 are invalid!" << endl;
            continue;
        }

        //Throws exception if the day of birth is greater than 31
        try {
            if (!(digit(ID,6) >= 0 && digit(ID,6) <=3))
                throw 1;
        }  catch (...) {
            cout << "Digits 6 and/or 7 are invalid!" << endl;
            continue;
        }

        //Throws exception if the day of birth is greater than 31
        try {
            if ((digit(ID,6) == 3 && digit(ID,7) > 1))
                throw 1;
        }  catch (...) {
            cout << "Digits 6 and/or 7 are invalid!" << endl;
            continue;
        }

        //Throws exception if the month is february and the and the day is above 29 (leap year case)
        try {
            if (digit(ID,4) == 0 && digit(ID,5) == 2 && digit(ID,6) == 2 && digit(ID,7) > 9)
                throw 1;
        }  catch (...) {
            cout << "Digits 6 and/or 7 are invalid!" << endl;
            continue;
        }

        //Throws exception if the last digit does not equal the equation with the civil Id inputs
        try {
            if ( digit(ID,12) != 11 - (((digit(ID,1)*2)+(digit(ID,2)*1)+(digit(ID,3)*6)+(digit(ID,4)*3)
                                     +(digit(ID,5)*7)+(digit(ID,6)*9)+(digit(ID,7)*10)+(digit(ID,8)*5)
                                     +(digit(ID,9)*8)+(digit(ID,10)*4)+(digit(ID,11)*2))% 11) )
                throw 1;
        }  catch (...) {
            cout << "The last digit is invalid!" << endl;
            continue;
        }

        cout << "You have entered a correct civil ID!" << endl;
        break;
    }

    CID id(ID);
    return 0;
}
//End of program
