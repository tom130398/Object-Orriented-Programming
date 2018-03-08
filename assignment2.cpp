#include <iostream>
#include <cstring>

using namespace std;
struct Property{char house[10]; char *car; char *boat;};
int main(void){
//Exercise 1:
	cout<<"Exercise 1:"<<endl;
	int i=0, x, a[10], t=0;
	int *ip;
	for(i=0; i<5; i++){
		cout<<"Input a interger number: ";
		cin>>a[i];
		ip=&a[i];
		x=*ip;
		t=t+x;
	}
	cout<<"The sum of numbers in array = "<<t<<endl;
	cout<<endl;

//Exercise 2
	cout<<"Exercise 2:"<<endl;
 	Property friends[] = { {"Yes",(char *)"0", (char *)"2"}, {"No",(char *)"1", (char *)"0"}, {"No", (char *)"0", (char *)"0"} };
 	Property *p;
	p=friends;
	for(i=0; i<(sizeof(friends)/sizeof(friends[0])); i++) {
	cout<<"Friend "<<(i+1)<<" owns a house? "<<p[i].house;
 	cout<<"\tFriend "<<(i+1)<<" owns "<<p[i].car<<"car(s).";
	cout<<"\tFriend "<<(i+1)<<" owns "<<p[i].boat<<"boat(s)."<<endl;
 	}
	cout<<endl;

//Exercise 3
	cout<<"Exercise 3:"<<endl;
	int q=0;
	char *str={"H e l l o\0"};
	while (*(str+q) != '\0'){
        if(!isspace(*(str+q)))
            cout << *(str+q);
        q++;
    	}
	cout<<endl;

//Exercise 4
	cout<<"Exercise 4:"<<endl;
	int j, k, n, temp;
	char string[100];
	cout<<"Input the string: ";
	cin>>string;
	n=strlen(string);
	for(k=0; k<n; k++){
		for(j=k+1; j<n; j++){
			if(*(string+k)>*(string+j)){
				temp=*(string+k);
				*(string+k)=*(string+j);
				*(string+j)=temp;
			}
		}
	}
	cout<<string<<endl;

//Exercise 5
	cout<<"Exercise 5:"<<endl;
	int l=0, max_len;
	char *str1={"HelloThoma\0"};
	char *str2={"HelloThere\0"};
	if(strlen(str1)>strlen(str2))	max_len=strlen(str1);
	else	max_len=strlen(str2);
	while(l<max_len){
		if(*(str1+l) != *(str2+l))
            		cout << *(str1+l) << " is different to " << *(str2+l) << endl;
        	l++;
    	}

//Exercise 6
	cout<<"Exercise 6:"<<endl;
	int m=0, len1, len2, max;
	Property friends1[] = { {"Yes",(char *)"0",(char *)"2"}, {"No",(char *)"1",(char *)"0"}, {"No",(char *)"0",(char *)"0"} };
	Property friends2[] = { {"Yes",(char *)"1",(char *)"2"}, {"No",(char *)"1",(char *)"0"}, {"No",(char *)"1",(char *)"1"} };
	Property *p1;
	Property *p2;
	p1=friends1;
	p2=friends2;
	len1=sizeof(friends1)/sizeof(friends1[0]);
	len2=sizeof(friends2)/sizeof(friends2[0]);
	if(len1<len2)	max=len1;
	else	max=len2;
	while(m<max){
		if(*(p1[m].house)==*(p2[m].house))	cout<<"Friend "<<m+1<<" has the same value of house"<<endl;
		if((p1[m].car)==(p2[m].car))	cout<<"Friend "<<m+1<<" has the same value of car"<<endl;
		if((p1[m].boat)==(p2[m].boat))	cout<<"Friend "<<m+1<<" has the same value of boat"<<endl;
		cout<<endl;
		m++;
		
	}
}
