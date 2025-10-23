#include <iostream>
#include <string>
using namespace std;

#define SIZE 10
class Stack
{
    string arr[SIZE];
    int top;

public:
    Stack() { top = -1; }
    void push(string val)
    {
        if (top < SIZE - 1)
        {
            arr[++top] = val;
        }
    }
    bool isEmpty()
    {
        return top == -1;
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

int main()
{
    Stack s;
    s.push("Finish report");
    s.push("Email client");
    if (!s.isEmpty())
    {
        cout << "Top item: " << s.peek() << endl;
        s.pop();
    }
    return 0;
}
