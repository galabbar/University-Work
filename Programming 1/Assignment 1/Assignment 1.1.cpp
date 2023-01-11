#include <iostream>
using namespace std;
int main()
{
	double mile,km;
	cout<<"Enter distance in miles: ";
	cin>> mile;
	km=1.609*mile;
	cout<<"The equivalent distance is "<<km<<" kilometers";
}
