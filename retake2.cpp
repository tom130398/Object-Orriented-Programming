#include <iostream>
using namespace std;

class product {
        string name;
        string price;
        int amount;
public:
        void set_values(string, string, int);
        void print_values();
        friend product* search_product(string, product[], int);
};

void product::set_values(string name, string price, int amount){
        this->name = name;
        this->price = price;
        this->amount = amount;
}

void product::print_values(){
        cout << "Product " << this->name << " with price: " << this->price << " have amount: " << this->amount<<endl;
}

product * search_product(string check_name, product all_product[], int number_of_product){
        int i;
        for(i=0; i< number_of_product; i++){
                if (all_product[i].name == check_name){
                        return all_product + i;
                        break;
                }
        }
        return 0;
}

int main(void){
        int i, number_of_product=0;
        char choose;
        product *all_product = new product[100];
	number_of_product=5;
        for(i=0; i<number_of_product; i++){
                string s;
		string a;
		a.push_back((char)('a'+i));
                s.push_back((char)('0'+i));
                all_product[i].set_values(a,s, 100);
                all_product[i].print_values();
        }

        while(choose!='Q'){
                cout << "S: search based on product's name\nQ: quit" << endl;
                cin >> choose;
                switch(choose){
                        /*case 'A':{
                                //require input from user, set_value for the new employee in array
                                string name, id;
                                int salary;
                                cout << "Input name: ";
                                cin >> name;
                                cout << "Input id: ";
                                cin >> id;
				cout << "Input salary: ";
                                cin >> salary;
                                all_employee[number_of_employee++].set_values(name, id, salary);
                                cout <<"Added" << endl;
                                break;
                        }*/
                        /*case 'R':{
                                string id;
                                cout << "Input ID of employee who you want to remove: ";
                                cin >> id;
                                employee *found = search_employee(id, all_employee, number_of_employee);
                                //if employee found with id
                                if(found!=0){
                                        //move all other employee to one up in all_employee array
                                        int i = found - all_employee;
                                        number_of_employee--;
                                        for(;i<number_of_employee-1;i++)
                                                all_employee[i] = all_employee[i+1];
                                        cout << "Employee deleted!" << endl;
                                }
                                else
                                        cout << "No employee with that ID!" << endl;
                                break;
                        }*/
                        case 'S':{
                                string name;
                                cout << "Input name of product which you want to search: ";
                                cin >> name;
                                product *found = search_product(name, all_product, number_of_product);
				//if found employee with that id
                                if(found!= 0)
                                        found->print_values();
                                else
                                        cout << "No product with that name!" << endl;
                        break;
                        }
                        case 'Q':
                                cout << "See you next time!" << endl;
                                break;
                        default:
                                cout << "Invalid choice!" << endl;
                }
        }


        return 0;
}

