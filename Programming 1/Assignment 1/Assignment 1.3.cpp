#include <iostream>
using namespace std;
int main()
{
	int SECONDS,days,hours,minutes,seconds,x1,y1;
	double x,y;
	cout<<"Enter SECONDS: ";
	cin>>SECONDS;
	days=SECONDS/86400;
	x=SECONDS%86400;
	x1=x;
	hours=x/3600;
	y=x1%3600;
	y1=y;
	minutes=y/60;
	seconds=y1%60;
	cout<<"This amount of seconds equals "<<days<<" days, "<<hours<<" hours, "<<minutes<<" minutes and "<<seconds<<" seconds.";
}

