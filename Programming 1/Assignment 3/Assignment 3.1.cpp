#include <iostream>
using namespace std;
int main()
{
	int i,max,counterp=0,countern=0;
	double sump=0,sumn=0,avep,aven;
	cout<<"Enter an integer and terminate the loop with 0."<<endl;
	cin>>i;
	max=i;
	while (i!=0){
		if (i>0){
			sump+=i;
			counterp++;
		}
		if (i<0){
			sumn+=i;
			countern++;
		}
		if (i>max)
		   max=i;
		cin>>i;
	}
	if (counterp!=0){
		avep=sump/counterp;
		cout<<"The average of the positive numbers is "<<avep<<endl;
	}
	else
	   cout<<"There are no positive numbers"<<endl;
	if (countern!=0){
		aven=sumn/countern;
		cout<<"The average of the negative numbers is "<<aven<<endl;
	}
	else
	   cout<<"There are no negative numbers"<<endl;
	cout<<"The biggest integer entered is "<<max<<endl;
}
