#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    Node *insertatend(Node *node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }
        node->next = insertatend(node->next, value);
        return node;
    }
    void insert(int value)
    {
        head = insertatend(head, value);
    }

    void reverse_display(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        reverse_display(node->next);
        cout << node->data << " ";
    }
};
int main()
{
    LinkedList list;
    list.insert(55);
    list.insert(97);
    list.insert(23);
    list.insert(87);
    cout << "Linked list in reverse: ";
    list.reverse_display(list.head);
    cout << endl;
    return 0;
}