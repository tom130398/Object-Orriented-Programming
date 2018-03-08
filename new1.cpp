#include <iostream>
using namespace std;

 struct DATE {
   int dd, mm, yy;
 };

int main(void) {

DATE today = {29, 10, 2000};
DATE tom=today;

cout<<"Today is: "<<today.dd<<", "<<today.mm<<", "<<today.yy;
tom.dd = today.dd + 1;
cout<<"\nTomorrow is: "<<tom.dd<<", "<<tom.mm<<", "<<tom.yy<<endl;
return 0;
}
