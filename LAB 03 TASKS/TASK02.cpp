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

    void append(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void rotate(int k)
    {
        if (head == nullptr || k == 0)
        {
            return;
        }

        int length = 1;
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            length++;
        }

        if (k >= length)
        {
            cout << "Invalid rotation: k must be smaller than list size" << endl;
            return;
        }

        Node *last = temp;

        temp = head;
        for (int i = 1; i < k; i++)
        {
            temp = temp->next;
        }

        Node *newHead = temp->next;

        temp->next = nullptr;

        last->next = head;

        head = newHead;
    }
};

int main()
{
    LinkedList list;
    list.append(5);
    list.append(3);
    list.append(1);
    list.append(8);
    list.append(6);
    list.append(4);
    list.append(2);

    cout << "Original list: ";
    list.display();

    int k;
    cout << "Enter number of elements to move: ";
    cin >> k;

    list.rotate(k);

    cout << "After rotation: ";
    list.display();

    return 0;
}
