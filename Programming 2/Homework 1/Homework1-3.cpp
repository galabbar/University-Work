//CS142 ASSIGNMENT#1
//<Ghazi Najeeb Al-Abbar>
//IDE used: <QT>

#include <iostream>
using namespace std;

//Question three:
void nDimensionalArr ( ){
    int x[2][3][4]={{{0,1,2,3},{4,5,6,7},{8,9,10,11}},{{12,13,14,15},{16,17,18,19},{20,21,22,23}}};
   cout<<"x[2][3][4]={{{0,1,2,3},{4,5,6,7},{8,9,10,11}},{{12,13,14,15},{16,17,18,19},{20,21,22,23}}}"<<endl;
   cout<<"x[1][1][1]: "<<x[1][1][1]<<"\t\t"<<"*(*(*(x+1)+1)+1): "<<*(*(*(x+1)+1)+1)<<endl;
}

int main(){
    nDimensionalArr();
}
