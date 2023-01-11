//CS142 ASSIGNMENT#1
//<Ghazi Najeeb Al-Abbar>
//IDE used: <QT>

#include <iostream>
#include <string>
using namespace std;

//Question two:
string ToUpperStr(string s){
    for(int i=0;i<s.length();i++){//s.length() gives back the length of the string s.
        if (!(s[i]>='A'&&s[i]<='Z')&&!(s[i]>='a'&&s[i]<='z'))//This is for the case where the character isn't a letter. It returns an error message.
           return "Error";
        if (s[i]>='A'&&s[i]<='Z')//This is for the case where the letter is already capital.
           continue;
        s[i]=char(s[i]-32);//This changes small letters into capital.
    }
    return s;
}

int main(){//main function.
	string s;
	cout<<"Enter a string: ";
    cin>>s;
    cout<<ToUpperStr(s)<<endl;
}//end of program.
