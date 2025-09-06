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
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void segregateEvenOdd()
    {
        Node *evenHead = NULL;
        Node *evenTail = NULL;
        Node *oddHead = NULL;
        Node *oddTail = NULL;
        Node *temp = head;

        while (temp)
        {
            if (temp->data % 2 == 0)
            {
                if (!evenHead)
                {
                    evenHead = temp;
                    evenTail = evenHead;
                }
                else
                {
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            }
            else
            {
                if (!oddHead)
                {
                    oddHead = temp;
                    oddTail = oddHead;
                }
                else
                {
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
            }
            temp = temp->next;
        }

        if (evenTail)
        {
            evenTail->next = oddHead;
        }
        if (oddTail)
        {
            oddTail->next = NULL;
        }
        head = evenHead ? evenHead : oddHead;
    }
};

int main()
{
    LinkedList list;
    int arr[10] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};

    for (int i = 0; i < 10; i++)
    {
        list.insertEnd(arr[i]);
    }

    list.printList();
    list.segregateEvenOdd();
    list.printList();
    return 0;
}
