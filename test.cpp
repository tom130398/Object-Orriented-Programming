#include <iostream>
using namespace std;

int main()
{
	int numbers[30];
	int index;
	int days;
	int total=0;
	int ave;
	cout<<"How many days:";
	cin>>days;
	for(index=0; index<days; index++) {
		cout << "Input hours of workday " << index+1 <<":";
		cin >> numbers[index];
		total=total+numbers[index];
		ave=total/days;
	}
	
	cout<<"Total work hours: "<<total<<endl;
	cout<<"Average work day length: "<<ave<<endl;
	cout<<"Inputted hours:"<< numbers[index] <<endl;

	cout << endl;
}

