#include <iostream>
using namespace std;
int main()
{
	double original,discount;
	char season;
	cout<<"Enter the original price: ";
	cin>>original;
	if (original<=250){
		cout<<"Enter the season you are in\n(Enter s or S for summer seasons and w or W for winter seasons): ";
		cin>>season;
		if (season=='s' or season=='S'){
			discount=original*(1-0.1);
			cout<<"The price after discount is "<<discount<<endl;
		}
		else if (season=='s' or season=='W'){
			discount=original*(1-0.05);
			cout<<"The price after discount is "<<discount<<endl;
		}
		else
		   cout<<"There was an error"<<endl;
	}
	else{
		discount=original*(1-0.2);
		cout<<"The price after discount is "<<discount<<endl;
	}
} 
