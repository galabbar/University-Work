//CS142 ASSIGNMENT#1
//<Ghazi Najeeb Al-Abbar>
//IDE used: <QT>

#include <iostream>
#include <cmath>
using namespace std;

//Question one:
int BinaryNumber (int n){
    int i,j=0,count=0,index,m=n;
    int base2[20];
    //This restricts the function for n under 1 or over a million.
    for (i=19;i>=0;i--){
        base2[j]=pow(2,i);
        j++;
    }
    //This determines the length of the binary number.
    for(i=19;i>=0;i--){
        if (n>=base2[i])
           count++;
    }
    int Binary[count];
    index=20-count;
    for (i=0;i<count;i++)
       Binary[i]=0;
    //This loop writes down the binary number and puts each digit in the "Binary" array.
    for (i=0;i<count;i++){
        if (n>=base2[index]){
            n=n-base2[index];
            Binary[i]=1;
        }
        index++;
    }
    cout<<"The integer "<<m<<" in binary is ";
    for (i=0;i<count;i++)
       cout<<Binary[i];
    int consec1=0, max=0;
    //This loop determines which chain of 1's is longer.
    for (i=0;i<=count;i++){
        if (Binary[i]==1)
           consec1++;
        else{
           if (consec1>max)
              max=consec1;
            consec1=0;
        }
    }
    cout<<endl<<"the maximum number of consecutive 1's is ";
    return max;
}

int main(){//main function
    int n;
    cout<<"Enter a number between 1 and 1000000: ";
        cin>>n;
        cout<<BinaryNumber(n)<<endl;
}//end of program
