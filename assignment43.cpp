#include <iostream>
using namespace std;

struct customer{char name[100]; char id[80]; int amount;};
void info(customer* Customer, int count);
void sort(customer* Customer, int n);
void print(customer* Customer, int n);

int main(void){
	int n, i;
	cout<<"Input number of customer: ";
	cin>>n;
	customer Customer[n];
	for(i=0; i<n; i++)
		info(Customer, i);
	sort(Customer, n);
	print(Customer, n);
	return 0;
} 

void info(customer *Customer, int count){
	customer *new_Customer=new customer;
	cout<<"Input customer name: ";
	cin>>new_Customer->name;
	cout<<"Input customer id: ";
	cin>>new_Customer->id;
	cout<<"Input number of purchase: ";
	cin>>new_Customer->amount;
	Customer[count]=*new_Customer;
	delete new_Customer;
}

void sort(customer *Customer, int n){
	int i, j;
	customer temp;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++){
			if(Customer[i].amount<Customer[j].amount){
				temp = Customer[i];
				Customer[i] = Customer[j];
				Customer[j] = temp;
			}
		}
	
}

void print(customer *Customer, int n){
	int i;
	for(i=0; i<n; i++){
		cout<<"Customer name: "<<Customer[i].name<<" , id: "<<Customer[i].id<<" , purchased: "<<Customer[i].amount<<endl;
	}
}
