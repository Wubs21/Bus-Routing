#include <iostream>
#include <string.h>
using namespace std;
class BusRoute {
public:
    int routeNo;
    std::string arrTime;
    std::string departTime;
    std::string source;
    std::string destination;
    float distance;
};
class BusDriver {
public:
    std::string driverName;
    int driverID;
    int phoneNo;
    std::string email;

    void welcome_message();
};
class Bus {
public:
    int busID;
    std::string busName;
    BusRoute br;
    BusDriver bd;

    void add_bus(int);
    void edit_bus(int);
    void delete_bus(int);
    void add_busDriver(int);
    void edit_busDriver(int);
    void delete_busDriver(int);
};
class LogIn {
private:
    std::string userName;
    std::string password;
public:
	bool authenticate();
    void view_bus(Bus&, int);
    void view_busDriver(BusDriver&, int);
    void search_records(Bus&, int);
    void exit();
};
class System {
public:
    void menu(LogIn&);
};
bool LogIn::authenticate(){
	string username,password;
	cout<<" Enter UserName : "<<endl;
	cin>>username;
	cout<<" Enter Password : "<<endl;
	cin>>password;
	if(username=="wdfa" and password=="1255")
	{
		cout<<"Login Sucessfull!!"<<endl;
		
		cout<<"|----------------------------|"<<endl;
        cout<<"| DWFA Bus Routing System    |"<<endl;
        cout<<"|                            |"<<endl;
        cout<<"|----------------------------|"<<endl;
        cout<<endl;
       
        return true;
	}
	
	else{
		cout<<"Login Failed!! Incorrect username or password";
		return false;
	}
}

void LogIn::view_bus(Bus& bus, int busID) {
    if (bus.busID == busID) {
        std::cout << "Bus ID: " << bus.busID << std::endl;
        std::cout << "Bus Name: " << bus.busName << std::endl;
        std::cout << "Route Number: " << bus.br.routeNo << std::endl;
        std::cout << "Arrival Time: " << bus.br.arrTime << std::endl;
        std::cout << "Departure Time: " << bus.br.departTime << std::endl;
        std::cout << "Source: " << bus.br.source << std::endl;
        std::cout << "Destination: " << bus.br.destination << std::endl;
        std::cout << "Distance: " << bus.br.distance << std::endl;
        std::cout << "Driver Name: " << bus.bd.driverName << std::endl;
        std::cout << "Driver ID: " << bus.bd.driverID << std::endl;
        std::cout << "Driver Phone No: " << bus.bd.phoneNo << std::endl;
        std::cout << "Driver Email: " << bus.bd.email << std::endl;
    } else {
        std::cout << "Bus not found!" << std::endl;
    }
}

void LogIn::view_busDriver(BusDriver& bd, int driverID) {
    if (bd.driverID == driverID) {
        std::cout << "Driver Name: " << bd.driverName << std::endl;
        std::cout << "Driver ID: " << bd.driverID << std::endl;
        std::cout << "Phone No: " << bd.phoneNo << std::endl;
        std::cout << "Email: " << bd.email << std::endl;
    } else {
        std::cout << "Driver not found!" << std::endl;
    }
}

void LogIn::search_records(Bus& bus, int busID) {
    view_bus(bus, busID);
}

void LogIn::exit() {
    std::cout << "Termination Message" << std::endl;
}
#include <iostream>

void BusDriver::welcome_message() {
    std::cout << "Welcome!" << std::endl;
}
#include <iostream>

void Bus::add_bus(int newBusID) {
    busID = newBusID;
    std::cout << "Enter bus name: ";
    std::cin >> busName;
    std::cout << "Enter route number: ";
    std::cin >> br.routeNo;
    std::cout << "Enter arrival time: ";
    std::cin >> br.arrTime;
    std::cout << "Enter departure time: ";
    std::cin >> br.departTime;
    std::cout << "Enter source: ";
    std::cin >> br.source;
    std::cout << "Enter destination: ";
    std::cin >> br.destination;
    std::cout << "Enter distance: ";
    std::cin >> br.distance;
}

void Bus::edit_bus(int busID) {
    if (this->busID == busID) {
        std::cout << "Edit bus details:" << std::endl;
        std::cout << "Enter new bus name: ";
        std::cin >> busName;
        std::cout << "Enter new route number: ";
        std::cin >> br.routeNo;
        std::cout << "Enter new arrival time: ";
        std::cin >> br.arrTime;
        std::cout << "Enter new departure time: ";
        std::cin >> br.departTime;
        std::cout << "Enter new source: ";
        std::cin >> br.source;
        std::cout << "Enter new destination: ";
        std::cin >> br.destination;
        std::cout << "Enter new distance: ";
        std::cin >> br.distance;
    } else {
        std::cout << "Bus not found!" << std::endl;
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
        std::cout << "Bus deleted successfully." << std::endl;
    } else {
        std::cout << "Bus not found!" << std::endl;
    }
}

void Bus::add_busDriver(int driverID) {
    bd.driverID = driverID;
    std::cout << "Enter driver name: ";
    std::cin >> bd.driverName;
    std::cout << "Enter driver phone number: ";
    std::cin >> bd.phoneNo;
    std::cout << "Enter driver email: ";
    std::cin >> bd.email;
}

void Bus::edit_busDriver(int driverID) {
    if (bd.driverID == driverID) {
        std::cout << "Edit driver details:" << std::endl;
        std::cout << "Enter new driver name: ";
        std::cin >> bd.driverName;
        std::cout << "Enter new driver phone number: ";
        std::cin >> bd.phoneNo;
        std::cout << "Enter new driver email: ";
        std::cin >> bd.email;
    } else {
        std::cout << "Driver not found!" << std::endl;
    }
}

void Bus::delete_busDriver(int driverID) {
    if (bd.driverID == driverID) {
        bd.driverName.clear();
        bd.driverID = 0;
        bd.phoneNo = 0;
        bd.email.clear();
        std::cout << "Driver deleted successfully." << std::endl;
    } else {
        std::cout << "Driver not found!" << std::endl;
    }
}
#include <iostream>



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
        	  system("cls");
        std::cout << "1. Add Bus\n";
        std::cout << "2. Edit Bus\n";
        std::cout << "3. Delete Bus\n";
        std::cout << "4. Add Bus Driver\n";
        std::cout << "5. Edit Bus Driver\n";
        std::cout << "6. Delete Bus Driver\n";
        std::cout << "7. View Bus\n";
        std::cout << "8. View Bus Driver\n";
        std::cout << "9. Search Records\n";
        std::cout << "10. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Bus ID: ";
                std::cin >> id;
                bus.add_bus(id);
                break;
            case 2:
                std::cout << "Enter Bus ID: ";
                std::cin >> id;
                bus.edit_bus(id);
                break;
            case 3:
                std::cout << "Enter Bus ID: ";
                std::cin >> id;
                bus.delete_bus(id);
                break;
            case 4:
                std::cout << "Enter Driver ID: ";
                std::cin >> id;
                bus.add_busDriver(id);
                break;
            case 5:
                std::cout << "Enter Driver ID: ";
                std::cin >> id;
                bus.edit_busDriver(id);
                break;
            case 6:
                std::cout << "Enter Driver ID: ";
                std::cin >> id;
                bus.delete_busDriver(id);
                break;
            case 7:
                std::cout << "Enter Bus ID: ";
                std::cin >> id;
                login.view_bus(bus, id);
                break;
            case 8:
                std::cout << "Enter Driver ID: ";
                std::cin >> id;
                login.view_busDriver(bus.bd, id);
                break;
            case 9:
                std::cout << "Enter Bus ID: ";
                std::cin >> id;
                login.search_records(bus, id);
                break;
            case 10:
                login.exit();
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 10);
			}
			else {
				cout<<"Invalid Character try again!!!!"<<endl;
			}
		}while(ch!='Y'or ch!='y');
    
}

int main() {
	LogIn login;
    System sys;
    if(login.authenticate()){
    	    sys.menu(login);
	}
    else{
    	cout<<"Exsisting program due to failed login "<<endl;
	}
    return 0;
}


