//CS142 Assignment 3
//Ghazi Najeeb Al-Abbar
//QT IDE
//2181148914
//point.cpp

#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;

point::point(){
    x=0;
    y=0;
}
point::point(int X,int Y){
    x=X;
    y=Y;
}
void point::print(){
    cout<<"("<<x<<","<<y<<")"<<endl;
}
int point::getX() {return this->x;}
int point::getY() {return this->y;}
double point::getDistance(point p)
{return sqrt(pow(this->x-p.x,2)+pow(this->y-p.y,2));}
