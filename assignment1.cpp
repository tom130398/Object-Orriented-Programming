#include <iostream>
#include <string>
using namespace std;

struct INFO{char name[10]; unsigned int id; unsigned int grade;};
struct STU{double act; bool work; double per; unsigned pas:3;}stu;

int main(){
//Exercise 1
	int i;
	int a=1, b=1, c=1, t;

	cout<<"Exercise 1: "<<endl;
	//The 1st series
	for(i=1; i<=15; i++){
		if(i%2==0)	cout<<(i/2)-1;
		else	cout<<(i/2)+1;
		cout<<' ';
	}
	cout<<endl;

	//The 2nd series
	cout<< a << ' ' << b << ' ' << c << ' ';
	for(i=0; i<12; i++){
		t=a+b+c;
		a=b;
		b=c;
		c=t;
		cout<< t ;
		cout<<' ';
	}
	cout<<endl;

	//The 3rd series
	for(i=-1; i>=-15; i--){
		if(i%2==0)	cout<<i+2;
		else	cout<<i;
		cout<<' ';
	}
	cout<<endl;
	

//Exercise 2
	cout<<"Exercise 2: "<<endl;
	INFO sf[5]{
		 {"A", 1, 1},
		 {"B", 2, 2},
		 {"C", 3, 3},
		 {"D", 4, 4},
		 {"E", 5, 5}
	};
	INFO tempt;
	int k, j;
	for(k=0; k<5; k++){
		for(j=0; j<5; j++){
			if(sf[k].grade<sf[j].grade){
				tempt=sf[k];
				sf[k]=sf[j];
				sf[j]=tempt;

			}
		}
	}
	for(k=0; k<5; k++)	cout<<sf[k].name<<' '<<sf[k].id<<' '<<sf[k].grade<<endl;


//Exercise 3

	cout<<"Exercise 3: "<<endl;
	cout<<"Enter the student's activeness for taking part into lectures and exercises: ";
	cin>>stu.act;
	cout<<"Project work done or not(1-done/0-not): ";
	cin>>stu.work;
	cout<<"Enter the percentage of points got from the exam: ";
	cin>>stu.per;
	if(stu.per>=40 && stu.work==1){
		if(stu.act>0.5)
			stu.pas=((stu.per-40)/15)+1;
		else
			stu.pas=(stu.per-40)/15;
		cout<<"The student passed the course with final grade: "<<stu.pas<<endl;
	}
	else	cout<<"The student didn't pass the course !"<<endl;
}
