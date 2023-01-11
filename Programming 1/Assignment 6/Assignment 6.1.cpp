#include <iostream>
using namespace std;

void readarray(float array[],int T){
    int i, element;
    for (i=0;i<T;i++){
        cin>>element;
        array[i]=element;
    }
}

float max_element(float array[], int T){
    int i,max=INT_MIN;
    for (i=0; i<T;i++){
        if (array[i]>max)
           max=array[i];
    }
    return max;
}
int main(){
    int M,N,count=0,i;
    float A[M],B[N];
    cout<<"Enter M and N: ";
    cin>>M>>N;
    cout<<"Enter "<<M<<" elements for the first array: ";
    readarray(A,M);
    cout<<"Enter "<<N<<" elements for the second array: ";
    readarray(B,N);
    for (i=0;i<N;i++){
        if (B[i]>max_element(A,M))
           count++;
    }
    if (count!=0)
        cout<<"Number of integers in the second array that are greater than the maximum of the first array is "<<count;
    else
       cout<<"There are no integers in the second array that are greater than the maximum of the first one.";
}
