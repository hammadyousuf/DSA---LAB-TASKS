#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;
    Node(string val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(string val)
    {
        Node *n = new Node(val);
        n->next = top;
        top = n;
    }
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Stack s;
    s.push("x");
    s.push("=");
    double result = 12 + 13 - 5 * (0.5 + 0.5) + 1;
    s.push(to_string(result));
    s.display();
    return 0;
}
