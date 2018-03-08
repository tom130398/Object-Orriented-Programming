#include <iostream>
#include <cstring>
using namespace std;

char** create(char **names, int n);
void sort(char **names, int n);
void print(char **names, int n);

int main(void){
	int n;
	cout<<"Enter the number of names you want to input: ";
	cin>>n;
	char** names=new char*[n];
	names=create(names, n);
	sort(names, n);
	print(names, n);
	return 0;
}

char** create(char **names, int n){
	int i;
	for(i=0; i<n; i++){
		names[i]=new char[100];
		cout<<"Input names: ";
		cin>>names[i];
	}
	return names;
}

void sort(char **names, int n){
	int i, j;
    	char temp[80];
	for(i=0;i<n;i++)
        	for(j=i+1;j<n;j++){
            		if(strcmp(names[i],names[j]) > 0){
                		strcpy(temp,names[i]);
                		strcpy(names[i],names[j]);
                		strcpy(names[j],temp);
            		}
        	}
}

void print(char **names, int n){
	int i;
	for(i=0; i<n; ++i){
		cout<<names[i]<<endl;
	}
}
