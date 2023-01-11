#include <iostream>
using namespace std;
int main()
{
	int int1,int2,int3,result,sum;
	cout<<"Enter two integers: ";
	cin>>int1>>int2;
	result=int1+int2;
	if (result>0){
		cout<<"enter a third integer: ";
		cin>>int3;
		sum=result+int3;
		if (sum>100)
		   cout<<"This sum is greater than 100";
		else
		   cout<<"This sum is not greater than 100";
		
	}
	else{
		if (int1>int2){
			cout<<int2<<", "<<int1;
		}
		else
		   cout<<int1<<", "<<int2;
	}
 } 
