#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = tail = NULL;
    }

    void insertEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

DoublyLinkedList concatenate(DoublyLinkedList &L, DoublyLinkedList &M)
{
    if (!L.head)
    {
        return M;
    }
    if (!M.head)
    {
        return L;
    }
    L.tail->next = M.head;
    M.head->prev = L.tail;
    L.tail = M.tail;
    return L;
}

int main()
{
    DoublyLinkedList L, M;

    L.insertEnd(1);
    L.insertEnd(2);
    L.insertEnd(3);

    M.insertEnd(4);
    M.insertEnd(5);
    M.insertEnd(6);

    cout << "List L: ";
    L.printList();

    cout << "List M: ";
    M.printList();

    DoublyLinkedList result = concatenate(L, M);

    cout << "Concatenated List: ";
    result.printList();

    return 0;
}
