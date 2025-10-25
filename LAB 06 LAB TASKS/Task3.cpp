#include <iostream>
#include <string>
using namespace std;

struct Order
{
    int id;
    string item;
    int quantity;
};

struct Node
{
    Order data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void enqueue(Order o)
    {
        Node *newNode = new Node;
        newNode->data = o;
        newNode->next = NULL;

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Order Added -> ID: " << o.id << ", Item: " << o.item << ", Qty: " << o.quantity << endl;
    }

    Order dequeue()
    {
        Order temp = {0, "None", 0};

        if (isEmpty())
        {
            cout << "No orders to process! (Queue Underflow)\n";
            return temp;
        }

        Node *delNode = front;
        temp = delNode->data;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete delNode;
        cout << "Processing Order -> ID: " << temp.id << ", Item: " << temp.item << ", Qty: " << temp.quantity << endl;
        return temp;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No pending orders!\n";
            return;
        }

        Node *temp = front;
        cout << "\n--- All Orders (In Order Received) ---\n";
        while (temp != NULL)
        {
            cout << "Order ID: " << temp->data.id << " | Item: " << temp->data.item << " | Qty: " << temp->data.quantity << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Queue q;
    int idCounter = 1;

    cout << "Adding 3 Orders...\n";
    for (int i = 0; i < 3; i++)
    {
        Order o;
        o.id = idCounter++;

        if (i == 0)
        {
            o.item = "Burger";
            o.quantity = 2;
        }
        else if (i == 1)
        {
            o.item = "Pizza";
            o.quantity = 1;
        }
        else
        {
            o.item = "Fries";
            o.quantity = 3;
        }

        q.enqueue(o);
    }

    q.display();

    cout << "\nProcessing (Dequeuing) 1 Order...\n";
    q.dequeue();

    q.display();

    cout << "\nProcessing All Remaining Orders...\n";
    while (!q.isEmpty())
    {
        q.dequeue();
    }

    q.display();

    return 0;
}
