//Name: Ghazi Najeeb AL-Abbar
//ID: 2181148914
//in lab 8

#include <stdio.h>
#include <math.h>

typedef struct point{

	double x;
	double y;
}Point;

double POINTdist(Point p1, Point p2){

	return sqrt( (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y) );
}

int main(){

	Point p1;
	Point p2;
	
	printf("Enter the x-coordinate for the first point: ");
	scanf("%lf",&p1.x);
	
	printf("Enter the y-coordinate for the first point: ");
	scanf("%lf",&p1.y);
	
	printf("Enter the x-coordinate for the second point: ");
	scanf("%lf",&p2.x);
	
	printf("Enter the y-coordinate for the second point: ");
	scanf("%lf",&p2.y);
	
	printf("The distance between the two points is %lf\n", POINTdist(p1,p2));
	
	return 0;
}
