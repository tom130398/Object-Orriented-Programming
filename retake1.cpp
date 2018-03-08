#include <iostream>
using namespace std;

struct product{char name[100]; char price[80]; int amount;};
void info(product* Product, int count);
void sort(product* Product, int n);
void print(product* Product, int n);

int main(void){
        int n, i;
        cout<<"Input number of product: ";
        cin>>n;
        product Product[n];
        for(i=0; i<n; i++)
                info(Product, i);
        sort(Product, n);
        print(Product, n);
        return 0;
}

void info(product *Product, int count){
        product *new_Product=new product;
        cout<<"Input product name: ";
        cin>>new_Product->name;
        cout<<"Input product price: ";
        cin>>new_Product->price;
        cout<<"Input number of purchase: ";
        cin>>new_Product->amount;
        Product[count]=*new_Product;
        delete new_Product;
}

void sort(product *Product, int n){
        int i, j;
        product temp;
        for(i=0; i<n; i++)
                for(j=i+1; j<n; j++){
                        if(Product[i].price<Product[j].price){
                                temp = Product[i];
                                Product[i] = Product[j];
                                Product[j] = temp;
                        }
                }

}

void print(product *Product, int n){
        int i;
        for(i=0; i<n; i++){
                cout<<"Product name: "<<Product[i].name<<" , price: "<<Product[i].price<<" , amount: "<<Product[i].amount<<endl;
        }
}

