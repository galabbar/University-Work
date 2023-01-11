#include <iostream>
using namespace std;

void interchange(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void reverse_array(int array[],int N){
	int i;
	if (N%2==0){
		for (i=0;i<N/2;i++)
			interchange(&array[i],&array[N-1-i]);
	}
	else{
		for (i=0;i<(N-1)/2;i++)
		   interchange(&array[i],&array[N-1-i]);
	}
}

int main(){
	int N,i;
	cout<<"Enter the size of your array: ";
	cin>>N;
	int A[N];
	cout<<"Enter your array:"<<endl;
	for(i=0;i<N;i++){
		cin>>A[i];
	}
	reverse_array(A,N);
	cout<<"This is the array in reverse:"<<endl;
	for (i=0;i<N;i++){
		cout<<A[i]<<" ";
	}
}
