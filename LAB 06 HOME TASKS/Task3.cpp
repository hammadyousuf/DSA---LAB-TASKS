#include <iostream>
#include <string>
using namespace std;

#define SIZE 100
class Stack
{
    char arr[SIZE];
    int top;

public:
    Stack() { top = -1; }
    void push(char c)
    {
        if (top < SIZE - 1)
        {
            arr[++top] = c;
        }
    }
    char pop()
    {
        return arr[top--];
    }
    char peek()
    {
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    string res = "";
    Stack stk;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            res += c;
        }
        else if (c == '(')
        {
            stk.push(c);
        }
        else if (c == ')')
        {
            while (!stk.empty() && stk.peek() != '(')
            {
                res += stk.pop();
            }
            stk.pop();
        }
        else
        {
            while (!stk.empty() && prec(stk.peek()) >= prec(c))
            {
                res += stk.pop();
            }
            stk.push(c);
        }
    }
    while (!stk.empty())
    {
        res += stk.pop();
    }
    cout << res;
    return 0;
}
