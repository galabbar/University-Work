//CS142 Assignment 3
//Ghazi Najeeb Al-Abbar
//QT IDE
//2181148914
//main.cpp

#include <iostream>
#include "rectangle.h"
#include "point.h"
using namespace std;

int main()
{
    int x1,y1,x2,y2;
    cout<<"Enter the x-y coordinates for the lower left vertix (enter x and then y): ";
    cin>>x1>>y1;
    cout<<"Enter the x-y coordinates for the upper right vertix (enter x and then y): ";
    cin>>x2>>y2;
    Rectangle myRectangle(x1,y1,x2,y2);
    point p1(x1,y1),p2(x2,y2);
    cout<<"Rectangle has lower left vertex @ Point:";
    p1.print();
    cout<<"and upper right vertex @ Point:";
    p2.print();
    cout<<"The area of your rectangle is: "<<myRectangle.getArea()<<endl;
    cout<<"The perimeter of your rectangle is: "<<myRectangle.getPerimetere()<<endl;
}
