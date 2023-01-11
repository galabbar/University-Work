//CS142 Assignment 3
//Ghazi Najeeb Al-Abbar
//QT IDE
//2181148914
//rectangle.cpp

#include "rectangle.h"
#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;

Rectangle::Rectangle(){
    point lowLeft(0,0);
    point upRight(0,0);
}
Rectangle::Rectangle(int x1,int y1,int x2,int y2):lowLeft(x1,y1),upRight(x2,y2){}
void Rectangle::print(){
    cout<<"The verticies of the rectagle are: ("<<lowLeft.getX()<<","<<lowLeft.getY()
       <<") , ("<<lowLeft.getX()<<","<<upRight.getY()<<") , ("<<upRight.getX()<<","
       <<upRight.getY()<<") , ("<<upRight.getX()<<","<<lowLeft.getY()<<")"<<endl;
}
/* The diagonal of the rectangle would be: d=√(x²+y²)
 * but it can be rearranged to be like this: x=√(d²-y²) or y=√(d²-x²)
 * Originally, the parimeter would be like: P=2*(x+y)
 * but in this case, it can be either P=2*(x+√(d²-x²)) or P=2*(y+√(d²-y²))
*/
double Rectangle::getPerimetere(){
    double X=lowLeft.x-upRight.x;
    double Y=lowLeft.y-upRight.y;
    double Perimetere=2*(abs(X)+sqrt(pow(lowLeft.getDistance(upRight),2)-pow(X,2)));
    return Perimetere;
}
/* The diagonal of the rectangle would be: d=√(x²+y²)
 * but it can be rearranged to be like this: x=√(d²-y²) or y=√(d²-x²)
 * Originally, the area would be A=x*y, but in this case
 * it can be either A=x*√(d²-x²) or A=y*√(d²-y²)
*/
double Rectangle::getArea(){
    double X=lowLeft.x-upRight.x;
    double Y=lowLeft.y-upRight.y;
    double Area=abs(X)*sqrt(pow(lowLeft.getDistance(upRight),2)-pow(X,2));
    return Area;
}
