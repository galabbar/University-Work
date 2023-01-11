#include <iostream>
using namespace std;

bool range(int x,int y,int z){
	if (y<=x and y>=z)
	   return true;
	return false;
}

int main(){
	int N,product=1,integer,i=0;
	cout<<"Enter N: ";
	cin>>N;
	cout<<"Enter "<<N<<" integers: "<<endl;
	while (i<N){
		cin>>integer;
		if (range(5,integer,-5)==true)
		   product*=integer;
		i++;
	}
	cout<<"Result = "<<product<<endl;
}
