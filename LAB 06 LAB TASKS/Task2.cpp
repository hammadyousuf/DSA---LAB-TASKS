#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Transaction
{
    int id;
    double amount;
    string desc;
    int flag; // 1 = Sale, 0 = Refund
};

struct Node
{
    Transaction t;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(Transaction t)
    {
        Node *newNode = new Node;
        newNode->t = t;
        newNode->next = top;
        top = newNode;
    }

    Transaction pop()
    {
        Transaction temp = {0, 0.0, "Empty", 0};
        if (top == NULL)
        {
            cout << "Stack Underflow!\n";
            return temp;
        }
        else
        {
            Node *del = top;
            temp = del->t;
            top = top->next;
            delete del;
            return temp;
        }
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void display()
    {
        Node *temp = top;
        cout << "\n--- Stack (Top to Bottom) ---\n";
        while (temp != NULL)
        {
            cout << "ID: " << temp->t.id << " | Amount: " << temp->t.amount << " | Desc: " << temp->t.desc << " | Flag: " << temp->t.flag << endl;
            temp = temp->next;
        }
    }
};

double applyDiscount(double amount)
{
    if (amount >= 1500)
    {
        return amount * 0.70;
    }
    else if (amount >= 1000)
    {
        return amount * 0.85;
    }
    else if (amount >= 500)
    {
        return amount * 0.95;
    }
    else
    {
        return amount;
    }
}

double evaluateSimpleExpression()
{
    double result = (100 + 20) * 0.9 - 5;
    return result;
}

int main()
{
    srand(time(0));

    Transaction list[7] = {
        {0, 1200, "Sale: Blue Jacket", 1},
        {0, 450, "Sale: Cotton Socks", 1},
        {0, -300, "Refund: Shirt", 0},
        {0, 1700, "Sale: Leather Jacket", 1},
        {0, 80, "Sale: Keychain", 1},
        {0, -50, "Refund: Minor Item", 0},
        {0, 520, "Sale: Sunglasses", 1}};

    Stack s;
    int idCounter = 1;

    cout << "Pushing 4 Random Transactions...\n";
    for (int i = 0; i < 4; i++)
    {
        int index = rand() % 7;
        Transaction t = list[index];
        t.id = idCounter++;

        if (t.amount > 0)
        {
            t.amount = applyDiscount(t.amount);
        }

        t.flag = (t.amount >= 0) ? 1 : 0;
        s.push(t);
    }

    s.display();

    cout << "\nExpression (100 + 20) * 0.9 - 5 = " << evaluateSimpleExpression() << endl;

    cout << "\nPopping one transaction (Reversal)...\n";
    if (!s.isEmpty())
    {
        Transaction popped = s.pop();
        cout << "Reversed Transaction: " << popped.desc << endl;
        popped.amount = -popped.amount;
        popped.desc += " [REVERSED]";
        popped.flag = (popped.amount >= 0) ? 1 : 0;
    }

    s.display();

    return 0;
}
