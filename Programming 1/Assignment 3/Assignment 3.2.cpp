#include <iostream>
using namespace std;
int main()
{
	int N,i=1,int1,int2,int3;
	cout<<"Enter N: ";
	cin>>N;
	cout<<endl;
	while (i<=N){
		cout<<"Enter 3 integers: ";
		cin>>int1>>int2>>int3;
		if (int1==int2 and int1==int3 and int2==int3)
		   cout<<"The 3 integers are equal"<<endl;
		else if (int1!=int2 and int1!=int3 and int2!=int3)
		   cout<<"3 different integers"<<endl;
		else
		   cout<<"2 of them are equal and the third is different"<<endl;
		i++;
		cout<<endl;
	}
}
