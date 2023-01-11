//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 5
//IDE: QT
//main.cpp

#include <iostream>
#include "mobileline.h"
using namespace std;

int main()
{ //Beginning of program
    int N, Line, Number, SMS;
    double  Minutes;
    cout << "Enter N: ";
    cin >> N;
    //Array of objects. It can be type telephoneline or mobileline, but not both
    TelephoneLine **LineArr = new TelephoneLine* [N];
    //Let's user choose which line it wants, and enter the information needed.
    for (int i = 0; i < N; i++)
    {
        cout << "Type 1 for Land Line, and 2 for Mobile Line: ";
        cin >> Line;
        //If the user chose Land line
        if ( Line == 1)
        {
            cout << "Enter your number: ";
            cin >> Number;
            cout << "Enter the number of minutes: ";
            cin >> Minutes;
            LineArr[i] = new TelephoneLine(Number,Minutes);
        }
        //If the user chose Mobile line
        else
        {
            cout << "Enter your number: ";
            cin >> Number;
            cout << "Enter the number of minutes: ";
            cin >> Minutes;
            cout << "Enter the number of sms sent: ";
            cin >> SMS;
            LineArr[i] = new MobileLine(Number,Minutes,SMS);
        }
    }
    //Prints out the information that the user has inputed
    for (int i = 0; i < N; i++)
    {
        cout << "--------------------------" << endl;
        LineArr[i]->print();
        cout << "Bill: " << LineArr[i]->CalcBill() << " fils" << endl;
    }

    //Deletes array of objects
    delete[] LineArr;
    return 0;
}//End of Program
