//this is a program which prints first 15 numbers of the following series
#include <iostream>
using namespace std;

int main()
{
        //the first series
        int a=1, b=0, c=2;
        int i;

	cout<<a<<' '<<b<<' '<<c<<' '; 
        for(i=3; i<15; i++)
                {
                        if(i%2==0)
                               cout<<(i-2)/2;
                        else
                                cout<<(i-1)/2;
			cout<<' ';
                }
	cout<<endl;
}

