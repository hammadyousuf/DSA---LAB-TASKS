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

    void insertEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void rearrange()
    {
        if (!head || !head->next)
        {
            return;
        }
        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = even;

        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        Node *prev = NULL;
        Node *curr = evenHead;
        Node *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        odd->next = prev;
    }
};

int main()
{
    LinkedList list;
    int arr[8] = {10, 4, 9, 1, 3, 5, 9, 4};
    for (int i = 0; i < 8; i++)
    {
        list.insertEnd(arr[i]);
    }

    list.printList();
    list.rearrange();
    list.printList();
    return 0;
}
