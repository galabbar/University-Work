#include <iostream>
using namespace std;
int main()
{
	int int1,int2,int3;
    float average;
    cout<<"Enter three integers: ";
    cin>>int1>>int2>>int3;
	average=(int1+int2+int3)/3;
	if (average<30){
		cout<<"small";
	}
	else if (average>=30 and average<120){
		cout<<"Intermediate";
	}
	else if (average>=120 and average<190){
		cout<<"Large";
	}
	else{
		cout<<"Very Large";
	}
    
 } 
