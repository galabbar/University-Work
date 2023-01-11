#include <iostream>
using namespace std;
int main()
{
	double initial,length,width,final;
	cout<<"Enter cost of constructing 1 meter of the fence in KD: ";
	cin>>initial;
	cout<<endl<<"Enter the length and width of the garden: ";
	cin>>length>>width;
	final=2*(length+width)*initial;
	cout<<endl<<"The cost of building the fence is: "<<final<<" KD.";
}
