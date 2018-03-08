
/*#include <iostream>
#include <cstdlib>
#include <new>
#include <cstring>
using namespace std;

#define NLEN 15
#define ALEN 200
#define DLEN 20

class Hotel {
	char name[NLEN];
	char address[ALEN];
	unsigned stars_no;
	unsigned rooms_no;
public:
	Hotel(char *name, char *address, unsigned stars_no, unsigned rooms_no);
	Hotel();
	~Hotel();
	void print_info();
};
 
class Room{
	unsigned room_no;
	double area;
	char type[7];//= {"single", "double", "suite"};
        double price;
public:
	Room();
        Room(unsigned room_no, double area, char *type, double price);
        ~Room();
        void print_info();
        void is_free();
        Room *search_room(unsigned room_no);
};

class Customer{
	char name[NLEN];
        char address[ALEN];
        unsigned room_no;
        char arrival[DLEN];
        unsigned stay_length;
public:
        Customer();
        Customer(char *name, char *address, unsigned room_no, char *arrival, unsigned stay_length);
        ~Customer();
        Customer* search_customer(unsigned room_no);
        void print_info();
        void get_roomInfo();
        void get_total();
        unsigned get_room_number();
};
/////  FOR HOTEL  //////////////////////////

Hotel::Hotel(){};
Hotel::~Hotel(){};
Hotel::Hotel(char *name, char *address, unsigned stars_no, unsigned rooms_no){
	strcpy(this->name, name);
        strcpy(this->address, address);
        this->stars_no = stars_no;
        this->rooms_no = rooms_no;
}

void Hotel::print_info(){
	cout << "Hotel name: " << this->name << endl;
        cout << "address: " << this->address << endl;
        cout << "number of stars: " << this->stars_no << endl;
        cout << "number of rooms: " << this->rooms_no << endl;
}

/////// FOR ROOMS  /////////////////////////////
Room::Room(){};
Room::~Room(){};
Room::Room(unsigned room_no, double area, char *type, double price){
	this->room_no = room_no;
        this->area = area;
        strcpy(this->type, type);
        this->price = price;
}

void Room::print_info(){
	cout << "Room number: " << this->room_no << endl;
        cout << "area: " << this->area << endl;
        cout << "type: " << this->type << endl;
        cout << "price: " << this->price << endl;
}

Room* Room::search_room(unsigned room_no){
	if (this->room_no == room_no){
		return this;
	}
        else{
        	return NULL;
        }
}

///////  FOR CUSTOMERS  ////////////////////////////

Customer::Customer(){}
Customer::~Customer(){}

Customer::Customer(char *name, char *address, unsigned room_no, char *arrival, unsigned stay_length){
	strcpy(this->name, name);
        strcpy(this->address, address);
        strcpy(this->arrival, arrival);
        this->room_no = room_no;
        this->stay_length = stay_length;
}

void Customer::print_info(){
	cout << "Customer's name: " << this->name << endl;
        cout << "address: " << this->address << endl;
        cout << "arrival: " << this->arrival << endl;
        cout << "stay lenght: " << this->stay_length << " days" << endl;
        cout << "room number: " << this->room_no << endl;
}

Customer* Customer::search_customer(unsigned room_no){
	if (this->room_no == room_no){
        	return this;
        }
        else{
        	return NULL;
        }
}

void check_customer(Customer **customers, unsigned tempNo, int size){
	Customer *tempC = NULL;
        for (int i = 0; i<size; i++){
        	if ((tempC = customers[i]->search_customer(tempNo)) != NULL){
                	tempC->print_info();
		}
	}
        delete tempC;
}

unsigned Customer::get_room_number(){
	return this->room_no;
}

void Customer::get_roomInfo(){
}

void get_total(){ 
}

Room* enlarge_roomArray(Room *room, int size) {
        Room *temp;
	try {
		temp = new Room[size];
        }
        catch (bad_alloc &xa) {
                cout << "\nAllocation failure\n";	
	}
        for (int j = 0; j<size - 1; j++)
		temp[j] = room[j];
        return temp;

}

Customer** enlarge_customerArray(Customer **customers, int size) {
	if(size==1)
        return new Customer*[size];
       	Customer **temp=customers;
        try {
		customers = new Customer*[size];
        }
        catch (bad_alloc &xa) {
        	cout << "\nAllocation failure\n";
        }
        for (int j = 0; j<size - 1; j++)
                temp[j] = customers[j];
                return temp;
	}

Customer** reduce_customerArray(Customer **customers, int *size, unsigned room_no) {
	int index = -1;
  	for (int i = 0; i<*size; i++){
		if (customers[i]->search_customer(room_no) != NULL){
		  index = i;
      	break;
    	}
  	cout << "index=" << index << endl;
  	if (index == -1)
  		return NULL;
  	Customer **temp = customers;
  		(*size)--;
  	try{
    		customers = new Customer*[*size];
  	}
  	catch (bad_alloc &xa) {
    		cout << "\nAllocation failure\n";
  	}
  	int k = 0;
    	for (int j = 0; j<(*size + 1); j++) {
      		if (j != index)
        		customers[k++] = temp[j];
    	}
   	 return customers;
  }
}

Room* reduce_roomArray(Room *room, int *size, unsigned room_no){
  	int index = -1;
  	for (int i = 0; i<*size; i++){
    		if (room[i].search_room(room_no) != NULL){
      			index = i;
      			break;
    		}
  	}
  	cout << "index=" << index << endl;
  	if (index == -1)
    		return NULL;
  	Room *temp = room;
  		(*size)--;
  	try{
    		room = new Room[*size];
  	}
  	catch (bad_alloc &xa) {
    		cout << "\nAllocation failure\n";
  	}
  	int k = 0;
  	for (int j = 0; j<(*size + 1); j++) {
    		if (j != index)
     			room[k++] = temp[j];
  	}
  	return room;
}

void init_customer(Customer **customer, Room *room, int index) {
  	char name[NLEN];
  	char address[ALEN];
  	char arrival[DLEN];
  	unsigned room_n;
  	unsigned stay;
  	int type, i = 1;
  	cout << "Name: ";
  	cin >> name;
  	cout << "Address: ";
  	cin >> address;
  	cout << "Arrival date (DD-MM-YY): ";
  	cin >> arrival;
  	cout << "Room number: ";
  	cin >> room_n;
  	cout << "Days of stay: ";
  	cin >> stay;
  	do{
    		cout << "What type of room? Single(1), Double(2) or suite(3) : ";
    		cin >> type;
    		switch (type){
      			case(1) :
        			room[index] = Room(room_n, 15.5, "Single", 95.49);
        			i = 0;
        			break;
      			case(2) :
        			room[index] = Room(room_n, 25.5, "Double", 155.49);
        			i = 0;
        			break;
      			case(3) :
        			room[index] = Room(room_n, 45.5, "Suite", 195.49);
        			i = 0;
        			break;
      			default:
      				cout << "Not a valid choice, input a valid room type";
    		}
    		cout << "\n";
    		cin.get();
  	} while (i != 0);
  		customer[index] = new Customer(name, address, room_n, arrival, stay);
}

void checkRoom(Room *room, unsigned tempNo, int size){
  	Room *tempR = NULL;
  	for (int i = 0; i<size; i++){
    		if ((tempR = room[i].search_room(tempNo)) != NULL){
      			tempR->print_info();
    		}
  	}
  	delete tempR;
}

int main(){
  	int size = 0;
  	Room *room = NULL;
  	Customer **customers = NULL;
  	Hotel *hotel;
  	static char hName[NLEN] = "Tekla 2";
  	static char hAddress[ALEN] = "Palosaarentie 60";
  	static unsigned hStars = 4;
  	static unsigned hRooms = 50;
  	char selection = 0x00;
  	hotel = new Hotel(hName, hAddress, hStars, hRooms);
  	while (true){
    		cout << "\nMENU: " << endl;
    		cout << "_________________________________" << endl;
    		cout << "H: Print Hotel information" << endl;
    		cout << "A: add new customer information" << endl;
    		cout << "D: delete customer's information" << endl;
    		cout << "M: print the list of booked rooms" << endl;
    		cout << "N: print the list of customers" << endl;
    		cout << "R: search based on room" << endl;
    		cout << "S: search based on customer" << endl;
    		cout << "Q: quit" << endl;
    		cout << "__________________________________" << endl;
    		cout << "Enter your selection: ";
    		cin.get(selection);
    		switch (tolower(selection)){
      			case 'a'://"A: add new customer information"
        			customers = enlarge_customerArray(customers, size + 1);
        			room = enlarge_roomArray(room, size + 1);
        			init_customer(customers, room, size);
        			cout << "---------------" << endl;
        			customers[size]->print_info();
        			room[size].print_info();
        			size++;
        			break;
      			case 'd'://"D: delete customer's information"
        			unsigned room_no;
        			cout << "Input Customer's room number: ";
        			cin >> room_no;
        			cin.get();
        			customers = reduce_customerArray(customers, &size, room_no);
        			room = reduce_roomArray(room, &size, room_no);
        			break;
      			case 'r'://"R: search based on room"
        			unsigned tempNo;
        			cout << "Input desired room number: ";
        			cin >> tempNo;
        			checkRoom(room, tempNo, size);
        			break;
      			case 'm'://"M: print the list of booked rooms"
        			for (int i = 0; i<(size); i++){
          				room[i].print_info();
        			}
         			break;
      			case 'n'://"N: print the list of customers"
        			for (int i = 0; i<(size); i++){
          				customers[i]->print_info();
        			}
        			break;
      			case 's'://"S: search 
        			cout << "Input Customer's room number: ";
        			cin >> room_no;
        			check_customer(customers, room_no, size);
        			break;
      			case 'q':// Quit
        			cout << "Thanks, see u next summer..."<<endl;
        			delete hotel;
        			delete[] room;
        			delete[] customers;
        			return 0;
        			break;
      			case 'h':// Hotel info
        			hotel->print_info();
        			break;
       	 		default:
        			cout << "Input a right value" << endl;
        			break;
    		}
    		cin.get();
 	 }
}*/
#include <iostream>
using namespace std;

class hotel;
class customer;

class Room {
    string room_number;
	double area;
	string type;
	double price_per_night;
	bool isReversed;
public:
    Room(){};
	Room(string room_number, double area, string type, double price_per_night){
		this->room_number = room_number;
		this->area = area;
		this->type = type;
		this->price_per_night = price_per_night;
		this->isReversed = false;
	}
	string getRoomNumber(){
		return this->room_number;
	}
	double getArea(){
		return this->area;
	}
	string getType(){
		return this->type;
	}
	double getPricePerNight(){
		return this->price_per_night;
	}
	bool isRoomReversed(){
		return this->isReversed;
	}
	void set_reversed(){
		this->isReversed = true;
	}
	void getInfo(){
		cout << "Room " << this->room_number << " with area of " << this->area << ". Type of room: " << this->type << " and price per night is: " << this->price_per_night << endl;
	}
};

class Customer {
	string name;
	string address;
	string room_number;
	string arrive_date;
	int nights;
	double totalPrice;
public:
    Customer(){};
	Customer(string name, string address, string room_number, string arrive_date, int nights){
		this->name = name;
		this->address = address;
		this->room_number = room_number;
		this->arrive_date = arrive_date;
		this->nights = nights;
		this->totalPrice = 0;
	}
	string getName(){
		return this->name;
	}
	string getAddress(){
		return this->address;
	}
	string getRoomNumber(){
		return this->room_number;
	}
	string getArriveDate(){
		return this->arrive_date;
	}
	int getNights(){
		return this->nights;
	}
	void setTotalPrice(double totalPrice){
		this->totalPrice = totalPrice;
	}
	void getInfo(){
		cout << this->name << " with address: " << this->address << " reverse room " << this->room_number << " from: " << this->arrive_date << " for " << this->nights << " nights. Total price: " << this->totalPrice << endl;
	}
};

class Hotel{
	string name;
	string address;
	int stars;
	int number_of_rooms;
public:
	Hotel(string name, string address, int stars, int number_of_rooms){
		this->name = name;
		this->address = address;
		this->stars = stars;
		this->number_of_rooms = number_of_rooms;
	}
	void getInfo(){
        cout << this->name << " in " << this->address << ". Star: " << this->stars << " with " << this->number_of_rooms << " rooms" << endl;
	}
};
void add_customer(Customer * all_customer, Room *all_room, int index){
	string name;
	string address;
	string arrive_date;
	string room_number;
	int nights, type, check = 1;
	double price_per_night;
	cout << "Name: ";
	cin >> name;
	cout << "Address: ";
	cin >> address;
	cout << "Arrival date: ";
	cin >> arrive_date;
	cout << "Room number: ";
	cin >> room_number;
	cout << "Nights of stay: ";
	cin >> nights;
	while (check==1) {
		cout << "What type of room? Single(1), Double(2) or suite(3) : ";
		cin >> type;
    	switch (type){
			case(1):
				price_per_night = 50;
				all_room[index] = Room(room_number, 10, "Single", price_per_night);
	            check = 0;
	            break;
			case(2):
				price_per_night = 100;
				all_room[index] = Room(room_number, 20, "Double", price_per_night);
				check = 0;
				break;
	  		case(3):
	  			price_per_night = 150;
				all_room[index] = Room(room_number, 30, "Suite", price_per_night);
	            check = 0;
	            break;
		default:
            cout << "Invalid choice" << endl;
		}
	}
	all_room[index].set_reversed();
	all_customer[index] = Customer(name, address, room_number, arrive_date, nights);
	all_customer[index].setTotalPrice(price_per_night * nights);
	cout << "Added customer" << endl;
}

int search_index_room(Room *all_room, int curr_room, string room_number){
    int i;
    for(i=1; i<=curr_room; i++)
        if (all_room[i].getRoomNumber().compare(room_number)==0)
            return i;
    return -1;
}

int search_index_customer(Customer *all_customer, int curr_customer, string room_number){
    int i;
    for(i=1; i<=curr_customer; i++)
        if (all_customer[i].getRoomNumber().compare(room_number)==0)
            return i;
    return -1;
}

void remove_customer(Customer *all_customer, Room *all_room, int curr_customer, int curr_room, string room_number){
    int index_room = search_index_room(all_room, curr_room, room_number);
    int index_customer = search_index_customer(all_customer, curr_customer, room_number);
    if(index_room != -1 && index_customer!=-1){
        cout << "Found!";
        for(;index_room<curr_room-1;index_room++)
            all_room[index_room] = all_room[index_room+1];
        for(;index_customer<curr_customer-1;index_customer++)
            all_customer[index_customer] = all_customer[index_customer+1];
        cout << "Deleted customer" << endl;
    }
    else
        cout << "Wrong room number";
}

int main(void){
	Room all_room[100];
	Customer all_customer[100];
	Hotel hotel("Max_star", "Vaasa", 5, 100);
	int curr_room = 0, curr_customer = 0;
	char selection;
//  curr_room++;
//	curr_customer++;
//	add_customer(all_customer, all_room, curr_customer);
//	all_room[1].getInfo();
//	cout << search_index_room(all_room, curr_room, "1") << endl;
//	cout << search_index_customer(all_customer, curr_customer, "1") << endl;
//	remove_customer(all_customer, all_room, curr_customer, curr_room, "1");
    while(true){
        cout << "\nMENU: " << endl;
        cout << "H: Print Hotel information" << endl;
        cout << "A: add new customer information" << endl;
        cout << "D: delete customer's information" << endl;
        cout << "M: print the list of booked rooms" << endl;
        cout << "N: print the list of customers" << endl;
        cout << "R: search based on room" << endl;
        cout << "S: search based on customer" << endl;
        cout << "Q: quit" << endl;
        cout << "__________________________________" << endl;
        cout << "Enter your selection: ";
        cin.get(selection);
        selection = tolower(selection);
        switch (selection){
            case 'h':// Hotel info
                hotel.getInfo();
                break;
            case 'a'://"A: add new customer information"
                curr_customer++;
                curr_room++;
                add_customer(all_customer, all_room, curr_customer);
                all_customer[curr_customer].getInfo();
                all_room[curr_room].getInfo();
                break;
            case 'd'://"D: delete customer's information"
            {
                string room_number;
                cout << "Input customer's room number to remove: ";
                cin >> room_number;
                remove_customer(all_customer, all_room, curr_customer, curr_room, room_number);
                break;
            }
            case 'r'://"R: search based on room"
            {
                string room_number;
                cout << "Input room number: ";
                cin >> room_number;
                int index_found = search_index_room(all_room, curr_room, room_number);
                all_room[index_found].getInfo();
                break;
            }
            case 'm'://"M: print the list of booked rooms"
            {
                for(int i=1; i<= curr_room; i++){
                    cout << "The following room is booked: " << endl;
                    if(all_room[i].isRoomReversed()) all_room[i].getInfo();
                }
                break;
            }
            case 'n'://"N: print the list of customers"
                for(int i=1; i<=curr_customer; i++)
                    all_customer[i].getInfo();
                break;
            case 's'://"S: search customer based on customer's room"
            {
                string room_number;
                cout << "Input customer's room number: ";
                cin >> room_number;
                int index_found = search_index_customer(all_customer, curr_customer, room_number);
                all_customer[index_found].getInfo();
                break;
            }
            case 'q':// Quit
                cout << "See you next time";
                break;
            default:
                cout << "Input a right value" << endl;
                break;
        }
        cin.get();
    }
	return 0;
}
