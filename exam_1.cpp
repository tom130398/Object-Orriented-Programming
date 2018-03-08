#include <iostream>
#include <cstdlib>
#include <new>
#include <cstring>
using namespace std;

#define NLEN 15
#define ALEN 200
#define DLEN 20


class Event{
        char name;
        char type[7];//= {"music", "movie", "dance"};
        char loc;
public:
        Event();
        Event(char *name, char *type, char *loc);
        ~Event();
        void print_info();
        void is_free();
        Event *search_event(char *name);
};

class Concert{
        unsigned duration;
        char date[DLEN];
        unsigned price;
public:
        Concert();
        Concert(unsigned duration, char *date, unsigned price);
        ~Concert();
        Concert* search_concert(unsigned price);
        void print_info();
        void get_concertInfo();
        void get_total();
        unsigned get_concert_price();
};

/////// FOR EVENT  /////////////////////////////
Event::Event(){};
Event::~Event(){};
Event::Event(char *name, char *type, char *loc){
	strcpy(this->name, name);
        strcpy(this->type, type);
	strcpy(this->loc, loc);
}

void Event::print_info(){
        cout << "Event name: " << this->name << endl;
        cout << "location: " << this->loc << endl;
        cout << "type: " << this->type << endl;

}

Event* Event::search_event(char *name){
        if (this->name == name){
                return this;
        }
        else{
                return NULL;
        }
}

///////  FOR CONCERT  ////////////////////////////

Concert::Concert(){}
Concert::~Concert(){}

Concert::Concert(unsigned duration, char *date, unsigned price){
        strcpy(this->date, date);
        this->duration = duration;
        this->price = price;
}

void Concert::print_info(){
        cout <<"Concert date: " << this->date << endl;
	cout << "duration: " << this->duration << endl;
        cout << "price: " << this->price << endl;
}

Concert* Concert::search_concert(unsigned price){
        if (this->price == price){
                return this;
        }
        else{
                return NULL;
        }
}

void check_concert(Concert **concerts, unsigned tempNo, int size){
        Concert *tempC = NULL;
        for (int i = 0; i<size; i++){
                if ((tempC = concerts[i]->search_concert(tempNo)) != NULL){
                        tempC->print_info();
                }
        }
        delete tempC;
}

unsigned Concert::get_concert_price(){
        return this->price;
}

void Concert::get_concertInfo(){
}

void get_total(){
}

Event* enlarge_eventArray(Event *event, int size) {
        Event *temp;
        try {
                temp = new Event[size];
        }
        catch (bad_alloc &xa) {
                cout << "\nAllocation failure\n";
        }
        for (int j = 0; j<size - 1; j++)
                temp[j] = event[j];
        return temp;

}

Concert** enlarge_concertArray(Concert **concerts, int size) {
        if(size==1)
        return new Concert*[size];
        Concert **temp=concerts;
        try {
                concerts = new Concert*[size];
        }
        catch (bad_alloc &xa) {
                cout << "\nAllocation failure\n";
        }
        for (int j = 0; j<size - 1; j++)
        temp[j] = concerts[j];
                return temp;
        }

Concert** reduce_concertArray(Concert **concerts, int *size, unsigned price) {
        int index = -1;
        for (int i = 0; i<*size; i++){
                if (concerts[i]->search_concert(price) != NULL){
                  index = i;
        break;
        }
        cout << "index=" << index << endl;
        if (index == -1)
                return NULL;
        Concert **temp = concerts;
                (*size)--;
        try{
                concerts = new Concert*[*size];
        }
        catch (bad_alloc &xa) {
                cout << "\nAllocation failure\n";
        }
        int k = 0;
        for (int j = 0; j<(*size + 1); j++) {
                if (j != index)
                        concerts[k++] = temp[j];
        }
         return concerts;
  }
}

Event* reduce_eventArray(Event *event, int *size, char *name){
        int index = -1;
        for (int i = 0; i<*size; i++){
                if (event[i].search_event(name) != NULL){
                        index = i;
                        break;
                }
        }
        cout << "index=" << index << endl;
        if (index == -1)
                return NULL;
        Event *temp = event;
                (*size)--;
        try{
                event = new Event[*size];
        }
        catch (bad_alloc &xa) {
                cout << "\nAllocation failure\n";
        }
        int k = 0;
        for (int j = 0; j<(*size + 1); j++) {
                if (j != index)
                        event[k++] = temp[j];
        }
        return event;
}

void init_concert(Concert **concert, Event *event, int index) {
        char date[DLEN];
        unsigned duration;
        unsigned price;
        int type, i = 1;
        cout << "duration: ";
        cin >> duration;
        cout << "price: ";
        cin >> price;
        cout << "date (DD-MM-YY): ";
        cin >> date;
        do{
                cout << "What type of Event? Music(1), Movie2) or Dance(3) : ";
                cin >> type;
                switch (type){
                        case(1) :
                                event[index] = Event("Pentatonix", "Music", "Hall A");
                                i = 0;
                                break;
                        case(2) :
                                event[index] = Event("Lion King", "Movie", "Hall B");
                                i = 0;
                                break;
			case(3) :
                                event[index] = Event("Samba", "Dance", "Hall C");
                                i = 0;
                                break;
                        default:
                                cout << "Not a valid choice, input a valid room type";
                }
                cout << "\n";
                cin.get();
        } while (i != 0);
                concert[index] = new Concert(duration, date, price);
}

void checkEvent(Event *event, unsigned tempNo, int size){
        Event *tempR = NULL;
        for (int i = 0; i<size; i++){
                if ((tempR = event[i].search_event(tempNo)) != NULL){
                        tempR->print_info();
                }
        }
        delete tempR;
}

int main(){
        int size = 0;
        Event *event = NULL;
        Concert **concerts = NULL;
	char selection = 0x00;
        while (true){
                cout << "\nMENU: " << endl;
                cout << "_________________________________" << endl;
                cout << "A: add new concert information" << endl;
                cout << "D: delete concert's information" << endl;
                cout << "M: print the list of events" << endl;
                cout << "N: print the list of concerts" << endl;
                cout << "E: search based on event" << endl;
                cout << "C: search based on concert" << endl;
                cout << "Q: quit" << endl;
                cout << "__________________________________" << endl;
                cout << "Enter your selection: ";
                cin.get(selection);
                switch (tolower(selection)){
                        case 'a'://"A: add new concert information"
                                concerts = enlarge_concertArray(concerts, size + 1);
                                event = enlarge_eventArray(event, size + 1);
                                init_concert(concerts, event, size);
                                cout << "---------------" << endl;
                                concerts[size]->print_info();
                                event[size].print_info();
                                size++;
                                break;
                        //case 'd'://"D: delete concert's information"
                                unsigned price;
                            //    cout << "Input Concert's price: ";
                              //  cin >> price;
                                //cin.get();
                                //concerts = reduce_concertArray(concerts, &size, price);
                                //event = reduce_eventArray(event, &size, name);
                                //break;
                        case 'e'://"E: search based on event"
                                unsigned tempNo;
                                cout << "Input desired event: ";
                                cin >> tempNo;
                                checkEvent(event, tempNo, size);
                                break;
                        case 'm'://"M: print the list of events"
                                for (int i = 0; i<(size); i++){
                                        event[i].print_info();
                                }
                                break;
                        case 'n'://"N: print the list of concerts"
                                for (int i = 0; i<(size); i++){
                                        concerts[i]->print_info();
                                }
                                break;
                        case 'c'://"C: search
                                cout << "Input Concert's price: ";
                                cin >> price;
                                check_concert(concerts, price, size);
                                break;
                        case 'q':// Quit
                                cout << "Thanks, see u next summer..."<<endl;
                                delete[] event;
                                delete[] concerts;
                                return 0;
                                break;
                        default:
                                cout << "Input a right value" << endl;
                                break;
                }
                cin.get();
         }
}

