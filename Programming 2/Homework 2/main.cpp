//main.cpp

#include <iostream>
#include "Circle.h"
using namespace std;

int main(){
	double r1,r2,v1,v2,temp;
	char d1,d2;
	Circle c1,c2;
	cout<<"Enter the length of the first and second radius: ";
	cin>>r1>>r2;
	c1.setRadius(r1);
	c2.setRadius(r2);
	cout<<"Enter the magnitude of the first and second velocities: ";
	cin>>v1>>v2;
	c1.increaseVelocity(v1);
	c2.increaseVelocity(v2);
	cout<<"Enter the first and second directions (U for up, D for down, L for left, and R for right): ";
	cin>>d1>>d2;
	c1.reverseDirection(d1);
	c2.increaseVelocity(3.5);
	temp=r1;
	r1=r2;
	r2=temp;
	cout<<"The radius of circle 1 is "<<c1
}
