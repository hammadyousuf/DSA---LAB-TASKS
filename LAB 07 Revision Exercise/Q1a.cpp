#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class dll
{
    Node *head;

public:
    dll()
    {
        head = nullptr;
    }
    void insertnode(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
    void delete_front()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
    }
    void delete_last()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }
    void delete_atpos(int pos)
    {
        if (head == nullptr)
            return;
        if (pos == 1)
        {
            delete_front();
            return;
        }
        Node *temp = head;
        for (int i = 1; temp != nullptr && i < pos; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }
        delete temp;
    }
};

int main()
{
    dll list;
    list.insertnode(45);
    list.insertnode(32);
    list.insertnode(56);
    list.insertnode(89);
    list.insertnode(100);

    cout << "Original List: ";
    list.display();

    list.delete_front();
    cout << "After deleting front: ";
    list.display();

    list.delete_last();
    cout << "After deleting last: ";
    list.display();

    list.delete_atpos(3);
    cout << "After deleting at position 3: ";
    list.display();

    return 0;
}
