#include <iostream>
#include <string>

using namespace std;

struct BusRoute {
    int routeNo;
    string arrTime;
    string departTime;
    string source;
    string destination;
    float distance;
};

struct BusDriver {
    string driverName;
    int driverID;
    int phoneNo;
    string email;

    //void welcome_message();
};

struct Bus {
    int busID;
    string busName;
    BusRoute br;
    BusDriver bd;

    void add_bus(int);
    void edit_bus(int);
    void delete_bus(int);
    void add_busDriver(int);
    void edit_busDriver(int);
    void delete_busDriver(int);
};

struct LogIn {
private:
    string userName;
    string password;

public:
    bool authenticate();
    void view_bus(Bus&, int);
    void view_busDriver(BusDriver&, int);
    void search_records(Bus&, int);
    void exit();
};
  



bool LogIn::authenticate() {
    string username, password;
    cout << "Enter UserName: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    if (username == "wdfa" && password == "1255") {
        cout << "Login Successful!!" << endl;
        cout<<"|----------------------------|"<<endl;
        cout<<"|   DWFA Bus Routing System  |"<<endl;
        cout<<"|                            |"<<endl;
        cout<<"|----------------------------|"<<endl;
        return true;
    } else {
        cout << "Login Failed!! Incorrect username or password" << endl;
        return false;
    }
}

void LogIn::view_bus(Bus& bus, int busID) {
    if (bus.busID == busID) {
        cout << "Bus ID: " << bus.busID << endl;
        cout << "Bus Name: " << bus.busName << endl;
        cout << "Route Number: " << bus.br.routeNo << endl;
        cout << "Arrival Time: " << bus.br.arrTime << endl;
        cout << "Departure Time: " << bus.br.departTime << endl;
        cout << "Source: " << bus.br.source << endl;
        cout << "Destination: " << bus.br.destination << endl;
        cout << "Distance: " << bus.br.distance << endl;
        cout << "Driver Name: " << bus.bd.driverName << endl;
        cout << "Driver ID: " << bus.bd.driverID << endl;
        cout << "Driver Phone No: " << bus.bd.phoneNo << endl;
        cout << "Driver Email: " << bus.bd.email << endl;
    } else {
        cout << "Bus not found!" << endl;
    }
}

void LogIn::view_busDriver(BusDriver& bd, int driverID) {
    if (bd.driverID == driverID) {
        cout << "Driver Name: " << bd.driverName << endl;
        cout << "Driver ID: " << bd.driverID << endl;
        cout << "Phone No: " << bd.phoneNo << endl;
        cout << "Email: " << bd.email << endl;
    } else {
        cout << "Driver not found!" << endl;
    }
}

void LogIn::search_records(Bus& bus, int busID) {
    view_bus(bus, busID);
}

void LogIn::exit() {
    cout << "Termination Message" << endl;
}



void Bus::add_bus(int newBusID) {
    busID = newBusID;
    cout << "Enter bus name: ";
    cin >> busName;
    cout << "Enter route number: ";
    cin >> br.routeNo;
    cout << "Enter arrival time: ";
    cin >> br.arrTime;
    cout << "Enter departure time: ";
    cin >> br.departTime;
    cout << "Enter source: ";
    cin >> br.source;
    cout << "Enter destination: ";
    cin >> br.destination;
    cout << "Enter distance: ";
    cin >> br.distance;
}

void Bus::edit_bus(int busID) {
    if (this->busID == busID) {
        cout << "Edit bus details:" << endl;
        cout << "Enter new bus name: ";
        cin >> busName;
        cout << "Enter new route number: ";
        cin >> br.routeNo;
        cout << "Enter new arrival time: ";
        cin >> br.arrTime;
        cout << "Enter new departure time: ";
        cin >> br.departTime;
        cout << "Enter new source: ";
        cin >> br.source;
        cout << "Enter new destination: ";
        cin >> br.destination;
        cout << "Enter new distance: ";
        cin >> br.distance;
    } else {
        cout << "Bus not found!" << endl;
    }
}

void Bus::delete_bus(int busID) {
    if (this->busID == busID) {
        busID = 0;
        busName.clear();
        br.routeNo = 0;
        br.arrTime.clear();
        br.departTime.clear();
        br.source.clear();
        br.destination.clear();
        br.distance = 0.0;
        bd.driverName.clear();
        bd.driverID = 0;
        bd.phoneNo = 0;
        bd.email.clear();
        cout << "Bus deleted successfully." << endl;
    } else {
        cout << "Bus not found!" << endl;
    }
}

void Bus::add_busDriver(int driverID) {
    bd.driverID = driverID;
    cout << "Enter driver name: ";
    cin >> bd.driverName;
    cout << "Enter driver phone number: ";
    cin >> bd.phoneNo;
    cout << "Enter driver email: ";
    cin >> bd.email;
}

void Bus::edit_busDriver(int driverID) {
if (bd.driverID == driverID) {
        cout << "Edit driver details:" << endl;
        cout << "Enter new driver name: ";
        cin >> bd.driverName;
        cout << "Enter new driver phone number: ";
        cin >> bd.phoneNo;
        cout << "Enter new driver email: ";
        cin >> bd.email;
    } else {
        cout << "Driver not found!" << endl;
    }
}

void Bus::delete_busDriver(int driverID) {
    if (bd.driverID == driverID) {
        bd.driverName.clear();
        bd.driverID = 0;
        bd.phoneNo = 0;
        bd.email.clear();
        cout << "Driver deleted successfully." << endl;
    } else {
        cout << "Driver not found!" << endl;
    }
}
struct System {
    void menu(LogIn&);
};

void System::menu(LogIn& login) {
    Bus bus;
    int choice, id;
    
    char ch;
        do{
        	cout<<"Enter W or w to go to main menu"<<endl;
        	cin>>ch;
        	if(ch=='W' or ch=='w')
        	{
        do {
        	  //system("cls");
        cout << "1. Add Bus\n";
        cout << "2. Edit Bus\n";
        cout << "3. Delete Bus\n";
        cout << "4. Add Bus Driver\n";
        cout << "5. Edit Bus Driver\n";
        cout << "6. Delete Bus Driver\n";
        cout << "7. View Bus\n";
        cout << "8. View Bus Driver\n";
        cout << "9. Search Records\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Bus ID: ";
                cin >> id;
                bus.add_bus(id);
                break;
            case 2:
                cout << "Enter Bus ID: ";
                cin >> id;
                bus.edit_bus(id);
                break;
            case 3:
                cout << "Enter Bus ID: ";
                cin >> id;
                bus.delete_bus(id);
                break;
            case 4:
                cout << "Enter Driver ID: ";
                cin >> id;
                bus.add_busDriver(id);
                break;
            case 5:
                cout << "Enter Driver ID: ";
                cin >> id;
                bus.edit_busDriver(id);
                break;
            case 6:
                cout << "Enter Driver ID: ";
                cin >> id;
                bus.delete_busDriver(id);
                break;
            case 7:
                cout << "Enter Bus ID: ";
                cin >> id;
                login.view_bus(bus, id);
                break;
            case 8:
                cout << "Enter Driver ID: ";
                cin >> id;
                login.view_busDriver(bus.bd, id);
                break;
            case 9:
                cout << "Enter Bus ID: ";
                cin >> id;
                login.search_records(bus, id);
                break;
            case 10:
                login.exit();
                break;
            default:
                cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 10);
			}
			else {
				cout<<"Invalid Character try again!!!!"<<endl;
			}
		}while(ch!='W'or ch!='w');
}
int main() {
    LogIn login;
    System sys;
    if (login.authenticate()) {
        sys.menu(login);
    } else {
        cout << "Exiting program due to failed login" << endl;
    }
    return 0;
}
