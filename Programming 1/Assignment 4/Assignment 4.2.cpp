#include <iostream>
using namespace std;
int main()
{
	int N,i=0,c,j;
	cout<<"Enter N: ";
	cin>>N;
	while (i<N){
		cout<<"#";
		c=0;
		if (N-1-i!=0){
		for (j=0;j<N;j++){
			cout<<"$";
			c++;
			if (c==N-1-i)
			   cout<<endl;
		}
	    }
		i++;
	}
}
