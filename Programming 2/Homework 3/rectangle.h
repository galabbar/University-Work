//CS142 Assignment 3
//Ghazi Najeeb Al-Abbar
//QT IDE
//2181148914
//rectangle.h

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle
{
    public:
        Rectangle();
        Rectangle(int,int,int,int);
        void print();
        double getPerimetere();
        double getArea();
    private:
        point lowLeft;
        point upRight;
};

#endif
