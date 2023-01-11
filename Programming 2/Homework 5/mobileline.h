//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 5
//IDE: QT
//mobileline.h

#include "telephoneline.h"

#ifndef MOBILELINE_H
#define MOBILELINE_H

class MobileLine: public TelephoneLine //inheritence from telephoneline
{
public:
    MobileLine(); //Default constructor
    MobileLine(int,double,int); //user defined constructor
    void setSms(int);
    int getSms();
    void Increase(int);
    virtual double CalcBill() override; //Overrides the CalcBill function in telephoneline.h
    virtual void print() override; //Overrides the print function in telephoneline.h
private:
    int sms;
};

#endif // MOBILELINE_H
