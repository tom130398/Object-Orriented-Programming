#include <iostream>
using namespace std;

float st_sum(float n);
float nd_sum(float n);

int main(void){
	cout<<"Firs sum equal: "<<endl;
	cout << st_sum(7) << endl;
	cout << "Calculate second sum " << endl;
	cout << nd_sum(5) << endl;
	return 0;
}

float st_sum(float n){
    float sum;
    if(n==1)
        return 0.5;
    sum = 1 /( 2*n) + st_sum(n-1);
    return sum;
}

float nd_sum(float n){
    float sum;
    if(n==1)
        return -1.0/3.0;
    sum = - n/(2*n+1) + nd_sum(n-1);
    return sum;
}
