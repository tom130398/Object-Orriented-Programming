#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Event {
        protected:
                string name, type, location;
        public:
                Event () {
                        cin.ignore();
                        cout << "Event name: ";
                        getline (cin, name);
                        cout << "Event type: ";
                        getline (cin, type);
                        cout << "Event location: ";
                        getline (cin, location);
                }
                string get_name () {
                        return name;
                }
                string get_location () {
                        return location;
                }
};

class Concert: public Event {
        private:
                string date, duration;
                int price;
        public:
                Concert () {
                        cout << "Concert date: ";
                        getline (cin, date);
                        cout << "Concert duration: ";
                        getline (cin, duration);
                        cout << "Concert ticket price: ";
                        cin >> price;
                }
                void print_out () {
                        cout << "Concert Information" << endl;
                        cout << "Event name: " << name << endl;
                        cout << "Event type: " << type << endl;
                        cout << "Event location: " << location << endl;
                        cout << "Concert date: " << date << endl;
                        cout << "Concert duration: " << duration << endl;
                        cout << "Concert ticket price: " << price << endl;
                }
                string get_date () {
                        return date;
                }
                int get_price () {
                        return price;
                }

};

void search (Concert *& concertIn, int num) {
        int IsStop = 0;
        do {
                cout << "Search by:" << endl;
                cout << "1. Name." << endl;
                cout << "2. Location." << endl;
                cout << "3. Ticket price." << endl;
                cout << "4. Date." << endl;
                int a;
                cin >> a;
                cin.ignore();
                switch (a) {
                        case 1: {
                                string nameIn;
                                cout << "Name: ";
                                getline (cin, nameIn);
                                for (int i = 0; i < num; i++) {
                                        if (concertIn[i].get_name() == nameIn)  concertIn[i].print_out();
                                }
                                IsStop = 1;
                                break;
                        }
                        case 2: { 
                                string locationIn;
                                cout << "Location: ";
                                getline (cin, locationIn);
                                for (int i = 0; i < num; i++) {
                                        if (concertIn[i].get_location() == locationIn)  concertIn[i].print_out();
}
                                IsStop = 1;
                                break;
                        }
                        case 3: {
                                int priceIn;
                                cout << "Ticket price: ";
                                cin >> priceIn;
                                for (int i = 0; i < num; i++) {
                                        if (concertIn[i].get_price() == priceIn)        concertIn[i].print_out();
                                }
                                IsStop = 1;
                                break;
                        }
                        case 4: {
                                string dateIn;
                                cout << "Date: ";
                                getline (cin, dateIn);
                                for (int i = 0; i < num; i++) {
                                        if (concertIn[i].get_date() == dateIn)  concertIn[i].print_out();
                                }
                                IsStop = 1;
                                break;
                        }
                        default: {
                                break;
                        }
                }
        } while (!IsStop);
}

int main (int argc, char *argv[]) {
	int i=0;
	if(argc <2) {
	cout<<"\nInvalid number of arguments!";
	return 1;
	}
	ofstream file_output_stream(argv[1], ios::app | ios::binary);

	if(!file_output_stream.is_open()) {
 	cout<<endl<<"Cannot open file!";
 	return 1;
	}
        Concert *my_concert;
        int num;
        cout << "Number of concert: ";
        cin >> num;


        for (int i = 0; i < num; i++) {
                cout << "Concert " << i + 1 << endl;
                my_concert = new Concert ();
        }
	char choice='y';
	do{
	 file_output_stream << "Concert " <<my_concert[i].get_name() << ", type " << " and location is " << my_concert[i].get_location() << ". ";
         file_output_stream << "It start on date: " << my_concert[i].get_date() << " and cost " << my_concert[i].get_price() << endl;
	 i++;
	 cout<<"Do you want to continue? ";
 	 cin>>choice;
	 }while(choice=='y');
	file_output_stream.close();
	ifstream file_input_stream(argv[1], ios::in | ios::binary);
	file_input_stream.close();
        search (my_concert, num);

}

