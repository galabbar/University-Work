#include <iostream>
using namespace std;

bool isidentical(int array1[], int array2[], int N, int M){
    int i,count=0;
    if (N!=M)
       return false;
    for (i=0;i<N;i++){
        if (array1[i]==array2[i])
           count++;
    }
    if (count==N)
       return true;
    return false;
}

void readarray(int array[],int T){
    int i,element;
    for (i=0;i<T;i++){
        cin>>element;
        array[i]=element;
    }
}

int main(){
    int N,M,A[N],B[M];
    cout<<"Enter N and M: ";
    cin>>N>>M;
    cout<<"Enter "<<N<<" elements for the first array: ";
    readarray(A,N);
    cout<<"Enter "<<M<<" elements for the second array: ";
    readarray(B,M);
    if (isidentical(A,B,N,M)==true)
        cout<<"The two arrays you entered are identical";
    else
       cout<<"The two arrays you entered are not identical.";
}