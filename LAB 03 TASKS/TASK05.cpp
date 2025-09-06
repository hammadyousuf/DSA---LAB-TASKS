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
    Node *reverseList(Node *node)
    {
        Node *prev = NULL;
        Node *curr = node;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

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

    bool isPalindrome()
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        Node *slow = head;
        Node *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = reverseList(slow->next);

        Node *firstHalf = head;
        Node *temp = secondHalf;
        bool palindrome = true;
        while (temp != NULL)
        {
            if (firstHalf->data != temp->data)
            {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        slow->next = reverseList(secondHalf);

        return palindrome;
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

    cout << "\nLinked List: ";
    list.printList();

    if (list.isPalindrome())
    {
        cout << "Output: Linked List is a Palindrome\n";
    }
    else
    {
        cout << "Output: Linked List is NOT a Palindrome\n";
    }

    return 0;
}
