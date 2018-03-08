#include <iostream>
using namespace std;
struct room{int room_id; char type[32]; int customer_id;};
struct customer{int room_id; int customer_id; char name[32];};

int main(){
//Exercise 1
	cout<<"Exercise 1"<<endl;
	char *s1 = "Assignment 3 ";
    	char *p1 = s1;
    	char *s2 = "Exercise 1";
    	char *p2 = s1;
    	char *&rp = s1;
    	rp = s2;
	cout << p1 << s1 << endl;

//Exercise 2
	cout<<"Exercise 2"<<endl;
	int *array = new int[100];
	int low,high, i, count = 0;
	cout << "Enter the lower number: ";
	cin >> low;
	cout <<"Enter the higher number: ";
	cin >> high;
	while(low<=high){
	bool prime=true;
	for(i=2;i<=(low/2);i++){
		if(low%i == 0){
			prime = false;
			break;
		}
	}
	if(prime)
		array[count++] = low;
		low++;
	}
	cout<<"The list of prime numbers: "<<endl;
	for(i=0;i<count;i++)
		cout << array[i] << " "<<endl;
	delete array;

//Exercise 3
	cout<<"Exercise 3"<<endl;
	int r1, c1, r2, c2, a, b, k, j, sum=0;
	cout<<"Enter rows and columns of the 1st matrix: ";
	cin>>r1>>c1;
	cout<<"Enter rows and columns of the 2nd matrix: ";
	cin>>r2>>c2;
	if(c1!=r2)
		cout<<"Matrices order can't be multiplied"<<endl;
	else{
		int **matrix1=new int*[r1];
		for(j=0; j<r1; j++)
			matrix1[j]=new int[c1];
		int **matrix2=new int*[r2];
		for(j=0; j<r2; j++)
			matrix2[j]=new int[c2];

		cout<<"Enter the elements of the 1st matrix: ";
		for(a=0; a<r1; a++)
			for(b=0; b<c1; b++)
				cin>>matrix1[a][b];

		cout<<"Enter the elements of the 2nd matrix: ";
		for(a=0; a<r2; a++)
			for(b=0; b<c2; b++)
				cin>>matrix2[a][b];

		int **multiply=new int*[r1];
		for(j=0; j<r1; j++)
			multiply[j]=new int[c2];

		for(a=0; a<r1; a++){
			for(b=0; b<c2; b++){
				for(k=0; k<r2; k++){
					sum=sum+matrix1[a][k]*matrix2[k][b];
				}
			multiply[a][b]=sum;
			sum=0;
			}
		} 

		cout<<"Product of entered matrices: "<<endl;
		for(a=0; a<r1; a++){
			for(b=0; b<c2; b++)
				cout<<multiply[a][b]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}


//Exercise 4
	cout<<"Exercise 4:"<<endl;
	int l;
	customer* customers;
	room* rooms;
	int room_size, customer_size;

	cout<<"How many rooms? ";
	cin>>room_size;
	rooms=new room[room_size];
	for(l=0; l<room_size; l++) {
		cout<<"room id: ";
		cin>>rooms[l].room_id;
		cout<<"room type: ";
		cin>>rooms[l].type;
		cout<<"customer id: ";
		cin>>rooms[l].customer_id;
	}

	cout<<"How many customers? ";
	cin>>customer_size;
	customers=new customer[customer_size];
	for(l=0; l<customer_size; l++) {
		cout<<"customer name: ";
		cin>>customers[l].name;
		cout<<"customer id: ";
		cin>>customers[l].customer_id;
		cout<<"customer's room id: ";
		cin>>customers[l].room_id;
		if(rooms[l].room_id==customers[l].room_id)	cout<<"This room is ocupied by other customer"<<endl;
		else cout<<"Customer id: "<<customers[l].customer_id<<" room id "<<customers[l].room_id<<endl;
	}

	customers=NULL;
	rooms=NULL;
	delete[] customers;
	delete[] rooms;
	return 0;
}
