#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char ch)
    {
        if (top >= 100 - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack stack;
    string input = "BORROWROB";
    string reversed = "";

    for (int i = 0; i < input.length(); i++)
    {
        stack.push(input[i]);
    }

    while (!stack.isEmpty())
    {
        reversed += stack.pop();
    }

    cout << "Original string: " << input << endl;
    cout << "Reversed string: " << reversed << endl;

    if (input == reversed)
    {
        cout << "Result: The string is a PALINDROME." << endl;
    }
    else
    {
        cout << "Result: The string is NOT a palindrome." << endl;
    }

    return 0;
}
