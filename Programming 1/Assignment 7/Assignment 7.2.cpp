#include <iostream>
#include <cmath>
using namespace std;

void solve (float A, float B, float C, int *numSolutions, float *S1, float *S2){
    int d;
    d=(B*B)-(4*A*C);
    *S1=(-B+sqrt(d))/(2*A);
    *S2=(-B-sqrt(d))/(2*A);
    if (d<0)
        *numSolutions=0;
    else if (d==0)
        *numSolutions=1;
    else
        *numSolutions=2;
}

int main(){
    float a,b,c,sol1,sol2;
    int num,N,i;
    cout<<"Enter N: ";
    cin>>N;
    for (i=0;i<N;i++){
        cout<<"Enter the coeffeciants of your quadratic equation: ";
        cin>>a>>b>>c;
        solve(a,b,c,&num,&sol1,&sol2);
        if (num==0)
           cout<<"NO SOLUTIONS"<<endl;
        if (num==1)
           cout<<"The repeated solution is "<<sol1<<endl;
        if (num==2){
           cout<<"The first solution is "<<sol1<<endl;
           cout<<"The second solution is "<<sol2<<endl;
        }
    }
}
