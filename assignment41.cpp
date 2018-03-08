#include <iostream>
using namespace std;

int *max_num(int *arr, int n);
int *min_num(int *arr, int n);
void read(int *arr, int n);

int main(void){
	int n;
	cout<<"Enter the number of elements(1 to 100): ";
	cin>>n;
	int arr[n];
	read(arr, n);
	cout<<"Max number: "<<*max_num(arr, n)<<endl;
	cout<<"Min number: "<<*min_num(arr, n)<<endl;
	return 0;
}

void read(int *arr, int n){
	int i;
	for(i=0; i<n; i++){
		cout<<"Input numbers: ";
		cin>>arr[i];
	}
}

int *max_num(int *arr, int n){
	int i, *max_position=&arr[0], max=arr[0];
	for(i=1; i<n; i++){
		if(max<arr[i]){
			max=arr[i];
			max_position=&arr[i];
		}
	}
	return max_position;
}

int *min_num(int *arr, int n){
	int i, *min_position=&arr[0], min=arr[0];
	for(i=1; i<n; i++){
		if(min>arr[i]){
                	min=arr[i];
                        min_position=&arr[i];
		}
	}
	return min_position;
}
