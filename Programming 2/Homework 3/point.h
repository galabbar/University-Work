//CS142 Assignment 3
//Ghazi Najeeb Al-Abbar
//QT IDE
//2181148914
//point.h

#ifndef POINT_H
#define POINT_H

class point
{
    public:
        point();
        point(int,int);
        void print();
        int getX();
        int getY();
        double getDistance(point);
        friend class Rectangle;
    private:
        int x;
        int y;
};

#endif
