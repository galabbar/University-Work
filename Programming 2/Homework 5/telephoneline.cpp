//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 5
//IDE: QT
//telephoneline.cpp

#include "telephoneline.h"
#include <iostream>
using namespace std;

//Empty constructor (Default Constructor)
TelephoneLine::TelephoneLine()
{
    //empty
}

//User defined constructor
TelephoneLine::TelephoneLine(int N,double M): Number(N),Minutes(M){}

int TelephoneLine::getNumber()
{
    return this->Number;
}

void TelephoneLine::setMinutes(double M)
{
    this->Minutes = M;
}

double TelephoneLine::getMinutes()
{
    return this->Minutes;
}

//Increases minutes by amount I
void TelephoneLine::Increase(double I)
{
    Minutes += I;
}

//Calculates the phone bill by using the minutes given
double TelephoneLine::CalcBill()
{
    return this->Minutes * 20;
}

void TelephoneLine::print()
{
    cout << "Phone Number: " << this->Number << endl;
    cout << "Minutes Talked: " << this->Minutes << endl;
}
