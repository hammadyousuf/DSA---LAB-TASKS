#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string site;
    Node *next;
    Node(string s)
    {
        site = s;
        next = NULL;
    }
};

class Stack
{
    string arr[10];
    int top;

public:
    Stack() { top = -1; }
    void push(string s)
    {
        if (top < 9)
        {
            arr[++top] = s;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
    }
    string peek()
    {
        return arr[top];
    }
};

void removeFront(Node *&head)
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    Stack st;
    Node *head = NULL;
    for (int i = 4; i >= 0; i--)
    {
        Node *n = new Node(sites[i]);
        n->next = head;
        head = n;
        st.push(sites[i]);
    }
    removeFront(head);
    removeFront(head);
    st.pop();
    st.pop();
    cout << "Current page: " << st.peek();
    return 0;
}
