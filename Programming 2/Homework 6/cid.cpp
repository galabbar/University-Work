//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 6
//CS142
//IDE: QT
//cid.cpp

#include "cid.h"
#include <iostream>
using namespace std;

//Constructor takes a type long long variable and adds each digit to an array slot (variable must be 12 digits)
CID::CID(long long ID)
{
    long long digit = 10;
    for (int i = 11; i >= 0; i--)
    {
    IDN[i] = (ID % digit) / (digit/10);
    digit *= 10;
    }
}


