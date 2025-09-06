#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void createFromArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            appendatend(arr[i]);
        }
    }

    void appendatend(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void insertAtFront(int val)
    {
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }

    void insertAtPosition(int val, int pos)
    {
        if (pos == 1)
        {
            insertAtFront(val);
            return;
        }
        Node *newnode = new Node(val);
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Position out of range" << endl;
            delete newnode;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deleteValue(int val)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != val)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            return;
        }

        Node *todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    int arr[5] = {3, 1, 2, 5, 8};

    cout << "Array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    LinkedList list;
    list.createFromArray(arr, 5);

    cout << "Linked List after creation: ";
    list.display();

    list.appendatend(9);

    list.insertAtPosition(11, 3);

    list.insertAtFront(4);

    cout << "Linked List after insertions: ";
    list.display();

    list.deleteValue(1);
    list.deleteValue(2);
    list.deleteValue(5);

    cout << "Final Linked List after deletions: ";
    list.display();

    return 0;
}
