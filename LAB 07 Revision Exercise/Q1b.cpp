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
    Node *reverse(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node *temp = node->next;
        node->next = node->prev;
        node->prev = temp;
        if (node->prev == nullptr)
        {
            head = node;
            return head;
        }
        return reverse(node->prev);
    }
    void reverseList()
    {
        if (head != nullptr)
        {
            head = reverse(head);
        }
    }
};

int main()
{
    dll list;
    list.insertnode(10);
    list.insertnode(20);
    list.insertnode(30);
    list.insertnode(40);
    list.insertnode(50);

    cout << "Original List: ";
    list.display();

    list.reverseList();
    cout << "Reversed List: ";
    list.display();

    return 0;
}
