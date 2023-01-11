//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 5
//IDE: QT
//telephoneline.h

#ifndef TELEPHONELINE_H
#define TELEPHONELINE_H


class TelephoneLine  //Parent (Base) Class
{
public:
    TelephoneLine(); //Default constructor
    TelephoneLine(int,double); //User defined constructor
    int getNumber();
    void setMinutes(double);
    double getMinutes();
    void Increase(double);
    virtual double CalcBill(); //virtual keyword is used so it can be overriden by a derived class "mobileline.h"
    virtual void print(); //virtual keyword is used so it can be overriden by a derived class "mobileline.h"
private:
    int Number;
    double Minutes;
};

#endif // TELEPHONELINE_H
