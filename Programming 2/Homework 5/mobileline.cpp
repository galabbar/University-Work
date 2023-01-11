//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 5
//IDE: QT
//mobileline.cpp

#include "mobileline.h"
#include <iostream>
using namespace std;

//Empty Constructor (Default constructor)
MobileLine::MobileLine()
{
    //empty
}

//User defined constructor
MobileLine::MobileLine(int N,double M, int SMS): TelephoneLine(N,M),sms(SMS){}

void MobileLine::setSms(int S)
{
    sms = S;
}

int MobileLine::getSms()
{
    return sms;
}

//Increase the sms sent by amount I
void MobileLine::Increase(int I)
{
    sms += I;
}

//Calculates the phone bill by using both minutes and the sms sent
double MobileLine::CalcBill()
{
    //CalcBill from telephoneline can be used here because it is inherited
    return TelephoneLine::CalcBill() + this->sms * 35;
}

void MobileLine::print()
{
    //Print from telephoneline can be used here because it is inherited
    TelephoneLine::print();
    cout << "sms sent: " << sms <<endl;
}
