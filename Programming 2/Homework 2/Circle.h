//Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H
class Circle{

Circle();
public:
	double computeArea();
	double computeCircumference();
	void setRadius(double Radius);
	double getradius();
	void increaseVelocity(double I); //I is how much the velocity is increased
	double getVelocity();
	char getDirection();
	void reverseDirection(char Direction);
private:
	double radius, velocity;
	char direction;
};
#endif
