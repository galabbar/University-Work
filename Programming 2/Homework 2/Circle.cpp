//Circle.cpp

#include <iostream>
#include <cmath>
#include "Circle.h"
using namespace std;

Circle::Circle(){
   radius=velocity=0;
   direction='U';
}
double Circle::computeArea(){
   return (3.141592)*pow(radius,2);
}
double Circle::computeCircumference(){
   return 2*(3.141592)*radius;
}
void Circle::setRadius(double R){
   if (R>=0)
      radius=R;
   else
      radius=0;
}
double Circle::getradius(){
   return radius;
}
void Circle::increaseVelocity(double I){ //I is how much the velocity is increased
   velocity=velocity+I;
}
double Circle::getVelocity(){
   return velocity;
}
char Circle::getDirection(){
   return direction;
}
void Circle::reverseDirection(char Direction){
   switch (Direction){
      case ('U'):
         Direction='D';
         break;
      case ('D'):
         Direction='U';
         break;
      case ('L'):
         Direction='R';
         break;
      case ('R'):
         Direction='L';
         break;
       default:
       	Direction='D';
         break;
   }
   direction=Direction;
}  
