#include <iostream>
using namespace std;
int main()
{
	char i;
	int counter=0;
	cout<<"Enter any character and terminate the loop by entering #"<<endl;
	cin>>i;
	while (i!='#'){
		if (i>='0' and i<='9')
		   counter++;
		cin>>i;
	}
	cout<<"The number of digits entered is "<<counter;
}
