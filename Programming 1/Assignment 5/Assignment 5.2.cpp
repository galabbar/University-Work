#include <iostream>
using namespace std;

void triangle(){
	int n,N,i,j,c;
	cout<<"enter n: ";
	cin>>n;
	N=n;
	c=0;
	for (i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			cout<<N;
			if (j==i)
			   cout<<endl;
			N++;
		}
		c++;
		N=n-c;
	}
	N=n;
	c=n-2;
	for (i=1;i<=n-1;i++){
		N=n-c;
		for(j=n-1;i<=j;j--){
			cout<<N;
			if (j==i)
			   cout<<endl;
			N++;
		}
		c--;
	}
}

int main(){
	triangle();
}
