#include <iostream>
#include <string>
using namespace std;

class PassengerNode
{
public:
    string name;
    PassengerNode *next;

    PassengerNode(string value)
    {
        name = value;
        next = NULL;
    }
};

class PassengerList
{
public:
    PassengerNode *head;

    PassengerList()
    {
        head = NULL;
    }

    void insertSorted(string value)
    {
        PassengerNode *newNode = new PassengerNode(value);
        if (!head || head->name > value)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        PassengerNode *temp = head;
        while (temp->next && temp->next->name < value)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(string value)
    {
        if (!head)
        {
            return;
        }
        if (head->name == value)
        {
            PassengerNode *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        PassengerNode *temp = head;
        while (temp->next && temp->next->name != value)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            PassengerNode *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    bool search(string value)
    {
        PassengerNode *temp = head;
        while (temp)
        {
            if (temp->name == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void printList()
    {
        PassengerNode *temp = head;
        if (!temp)
        {
            cout << "No passengers reserved.\n";
            return;
        }
        while (temp)
        {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class FlightNode
{
public:
    string flightNumber;
    PassengerList passengers;
    FlightNode *next;

    FlightNode(string fnum)
    {
        flightNumber = fnum;
        next = NULL;
    }
};

class FlightList
{
public:
    FlightNode *head;

    FlightList()
    {
        head = NULL;
    }

    FlightNode *findFlight(string fnum)
    {
        FlightNode *temp = head;
        while (temp)
        {
            if (temp->flightNumber == fnum)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void addFlight(string fnum)
    {
        if (findFlight(fnum))
        {
            cout << "Flight already exists.\n";
            return;
        }
        FlightNode *newFlight = new FlightNode(fnum);
        newFlight->next = head;
        head = newFlight;
        cout << "Flight " << fnum << " added.\n";
    }

    void displayFlights()
    {
        FlightNode *temp = head;
        if (!temp)
        {
            cout << "No flights available.\n";
            return;
        }
        while (temp)
        {
            cout << "Flight: " << temp->flightNumber << endl;
            temp->passengers.printList();
            temp = temp->next;
        }
    }
};

int main()
{
    FlightList flights;
    int choice;
    string flightNum, name;

    while (true)
    {
        cout << "\n--- Airline Reservation System ---\n";
        cout << "1. Add Flight\n";
        cout << "2. Reserve Ticket\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Check Reservation\n";
        cout << "5. Display Flights & Passengers\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter flight number: ";
            cin >> flightNum;
            flights.addFlight(flightNum);
        }
        else if (choice == 2)
        {
            cout << "Enter flight number: ";
            cin >> flightNum;
            FlightNode *flight = flights.findFlight(flightNum);
            if (!flight)
            {
                cout << "Flight not found!\n";
                continue;
            }
            cout << "Enter passenger name: ";
            cin >> name;
            flight->passengers.insertSorted(name);
            cout << "Ticket reserved for " << name << " on flight " << flightNum << ".\n";
        }
        else if (choice == 3)
        {
            cout << "Enter flight number: ";
            cin >> flightNum;
            FlightNode *flight = flights.findFlight(flightNum);
            if (!flight)
            {
                cout << "Flight not found!\n";
                continue;
            }
            cout << "Enter passenger name: ";
            cin >> name;
            if (flight->passengers.search(name))
            {
                flight->passengers.deleteValue(name);
                cout << "Reservation for " << name << " on flight " << flightNum << " cancelled.\n";
            }
            else
            {
                cout << "No reservation found for " << name << " on flight " << flightNum << ".\n";
            }
        }
        else if (choice == 4)
        {
            cout << "Enter flight number: ";
            cin >> flightNum;
            FlightNode *flight = flights.findFlight(flightNum);
            if (!flight)
            {
                cout << "Flight not found!\n";
                continue;
            }
            cout << "Enter passenger name: ";
            cin >> name;
            cout << (flight->passengers.search(name) ? "Reserved\n" : "Not Reserved\n");
        }
        else if (choice == 5)
        {
            flights.displayFlights();
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
