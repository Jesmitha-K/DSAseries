#include <iostream>
#include <string>
using namespace std;

class User {
public:
    string name;
    string username;
    string password;

    User() {
        name = "";
        username = "";
        password = "";
    }
};

class Ticket {
public:
    int ticketId;
    string passengerName;
    string status;
    bool booked;

    Ticket() {
        ticketId = 0;
        passengerName = "";
        status = "";
        booked = false;
    }
};

class RailwayReservation {
private:
    User users[5];
    Ticket tickets[5];

    int userCount;
    int ticketCount;
    int nextTicketId;

public:
    RailwayReservation() {
        userCount = 0;
        ticketCount = 0;
        nextTicketId = 1001;
    }

    void registerUser() {
        if (userCount >= 5) {
            cout << "User limit reached!\n";
            return;
        }

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, users[userCount].name);

        cout << "Enter Username: ";
        cin >> users[userCount].username;

        cout << "Enter Password: ";
        cin >> users[userCount].password;

        userCount++;
        cout << "Registration Successful!\n";
    }

    void login() {
        string uname, pass;

        cout << "Enter Username: ";
        cin >> uname;

        cout << "Enter Password: ";
        cin >> pass;

        for (int i = 0; i < userCount; i++) {
            if (users[i].username == uname &&
                users[i].password == pass) {
                
            }
        }

        cout << "Invalid Credentials!\n";
        
    }

    void bookTicket() {
        if (ticketCount >= 5) {
            cout << "No tickets available!\n";
            return;
        }

        Ticket t;

        cout << "Enter Passenger Name: ";
        cin.ignore();
        getline(cin, t.passengerName);

        t.ticketId = nextTicketId++;
        t.booked = true;

        if (ticketCount == 0)
            t.status = "Confirmed";
        else if (ticketCount == 1)
            t.status = "Waiting List";
        else
            t.status = "RAC";

        tickets[ticketCount] = t;
        ticketCount++;

        cout << "\nTicket Booked Successfully!\n";
        cout << "Ticket ID: " << t.ticketId << endl;
        cout << "Status: " << t.status << endl;
    }

    void cancelTicket() {
        int id;
        cout << "Enter Ticket ID to cancel: ";
        cin >> id;

        int pos = -1;

        for (int i = 0; i < ticketCount; i++) {
            if (tickets[i].ticketId == id) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Ticket not found!\n";
            return;
        }

        for (int i = pos; i < ticketCount - 1; i++) {
            tickets[i] = tickets[i + 1];
        }

        ticketCount--;

       
        for (int i = 0; i < ticketCount; i++) {
            if (i == 0)
                tickets[i].status = "Confirmed";
            else if (i == 1)
                tickets[i].status = "Waiting List";
            else
                tickets[i].status = "RAC";
        }

        cout << "Ticket Cancelled Successfully!\n";
    }

    void displayTickets() {
        if (ticketCount == 0) {
            cout << "No tickets booked.\n";
            return;
        }

        cout << "\n----- Ticket Details -----\n";

        for (int i = 0; i < ticketCount; i++) {
            cout << "Ticket ID      : "
                 << tickets[i].ticketId << endl;

            cout << "Passenger Name : "
                 << tickets[i].passengerName << endl;

            cout << "Status         : "
                 << tickets[i].status << endl;

            cout << "--------------------------\n";
        }
    }
};

int main() {
    RailwayReservation rr;
    int choice;

    while (true) {
        cout << "\n===== Railway Reservation System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Book Ticket\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Display Tickets\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            rr.registerUser();
            break;

        case 2:
            rr.login();
            break;

        case 3:
            rr.bookTicket();
            break;

        case 4:
            rr.cancelTicket();
            break;

        case 5:
            rr.displayTickets();
            break;

        case 6:
            cout << "Thank You!\n";
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}