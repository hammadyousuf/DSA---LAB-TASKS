#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node(char val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertEnd(char val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void deleteValue(char val)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to delete.\n";
            return;
        }

        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL && curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Value " << val << " is not present in the list.\n";
            return;
        }

        if (prev == NULL)
        {
            cout << "Cannot delete the first node as per task instructions.\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Value " << val << " deleted successfully from the list.\n";
    }
};

int main()
{
    LinkedList list;
    int n;
    char val;

    cout << "Enter number of elements in Linked List: ";
    cin >> n;

    cout << "Enter elements (single character or digit): ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        list.insertEnd(val);
    }

    cout << "\nOriginal Linked List: ";
    list.printList();

    cout << "\nEnter a value to delete (not the first one): ";
    cin >> val;
    list.deleteValue(val);

    cout << "\nUpdated Linked List: ";
    list.printList();

    return 0;
}
