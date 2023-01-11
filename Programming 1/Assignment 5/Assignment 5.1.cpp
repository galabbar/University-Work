#include <iostream>
using namespace std;

int function(int x){
	int f;
	if (x<=6)
	   f=x+3;
	else if (x<=15)
	   f=(x*x)+3*x-4;
	else 
	   f=x-8;
	return f;
}

int main(){
	int S,E,sum=0;
	cout<<"Enter start and end: ";
	cin>>S>>E;
	for (S;S<=E;S++)
	   sum+=function(S);
	cout<<"Sum = "<<sum;
}

