#include <iostream>
using namespace std;
int main()
{
	int day1,day2,month1,month2;
	cout<<"Enter a day and month: ";
	cin>>day1>>month1;
	cout<<endl<<"Enter another day and month: ";
	cin>>day2>>month2;
	if (month1>month2)
	   cout<<endl<<"The first date is not before the second date."<<endl;
	else if (month2>month1)
	   cout<<endl<<"The first date is before the second date."<<endl;
	else if (month1==month2 and day1>day2)
	   cout<<endl<<"The first date is not before the second date."<<endl;
	else if (month1==month2 and day2>day1)
	   cout<<endl<<"The first date is before the second date."<<endl;
	else
	   cout<<endl<<"They are the same day!"<<endl;
}
