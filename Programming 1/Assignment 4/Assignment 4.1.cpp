#include <iostream>
using namespace std;
int main()
{
	int integer,N,i;
	double average,sum,min;
	cout<<"How many elements in the group: ";
	cin>>N;
	min=0;
	while (N>0){
		average=0;
		sum=0;
		cout<<"Enter "<<N<<" integers: ";
		for (i=0;i<N;i++){
			cin>>integer;
			sum+=integer;
		}
		average=sum/N;
		cout<<"Average = "<<average<<endl<<endl;
		if (min<=1 || min>average)
		   min=average;
		cout<<"How many integers in the group: ";
		cin>>N;
	}
	cout<<endl<<"The minimum average is "<<min<<endl;
	cout<<"program ended.";
}
