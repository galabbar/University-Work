#include <iostream>
using namespace std;

int main(){
    int i,j,M,N,element,A[10][10],max;
    cout<<"enter N and M: ";
    cin>>N>>M;
    cout<<"enter "<<N<<"x"<<M<<" matrix:"<<endl;
    for (i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin>>element;
            A[i][j]=element;
        }
    }
    cout<<endl;
    for (i=0;i<N;i++){
        for(j=0;j<M;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<endl;
    for (i=0;i<N;i++){
        max=INT_MIN;
        for(j=0;j<M;j++){
            if (A[i][j]>max)
               max=A[i][j];
        }
        cout<<"max integer in row"<<i<<":"<<max<<endl;
    }
    for (i=0;i<M;i++){
        max=INT_MIN;
        for(j=0;j<N;j++){
            if (A[j][i]>max)
               max=A[j][i];
        }
        cout<<"max integer in coloumn"<<i<<":"<<max<<endl;
    }
}
