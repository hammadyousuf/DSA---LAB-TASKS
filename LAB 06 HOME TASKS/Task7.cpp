#include <iostream>
#include <string>
using namespace std;

#define SIZE 10
class Queue
{
    string arr[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }
    void enqueue(string name)
    {
        if (rear < SIZE - 1)
        {
            if (front == -1)
            {
                front = 0;
            }
            arr[++rear] = name;
        }
    }
    void dequeue()
    {
        if (front != -1 && front <= rear)
        {
            front++;
        }
    }
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue q;
    q.enqueue("Ali");
    q.enqueue("Sara");
    q.enqueue("Ahmed");
    q.dequeue();
    q.display();
    return 0;
}
