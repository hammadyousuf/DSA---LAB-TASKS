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
        next = NULL;
    }
};
class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void insertEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void insertBegin(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtPos(int val, int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1)
        {
            insertBegin(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty!\n";
            return;
        }

        Node *curr = head;
        Node *prev = NULL;

        if (head->data == val)
        {
            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            last->next = head->next;
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        do
        {
            prev = curr;
            curr = curr->next;
            if (curr->data == val)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);

        cout << "Node not found!\n";
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main()
{
    CircularLinkedList cll;
    cll.insertEnd(1);
    cll.insertEnd(2);
    cll.insertEnd(3);
    cll.insertEnd(4);

    cout << "Initial Circular Linked List: ";
    cll.printList();

    cll.insertBegin(0);
    cout << "After inserting 0 at beginning: ";
    cll.printList();

    cll.insertAtPos(6, 4);
    cout << "After inserting 6 at position 4: ";
    cll.printList();

    cll.deleteNode(4);
    cout << "After deleting node with value 4: ";
    cll.printList();

    cll.deleteNode(0);
    cout << "After deleting node with value 0 (head): ";
    cll.printList();

    return 0;
}
