#include <iostream>
#include <string>
using namespace std;

#define SIZE 10
class Queue
{
    int arr[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }
    void enqueue(int val)
    {
        if (rear < SIZE - 1)
        {
            if (front == -1)
            {
                front = 0;
            }
            arr[++rear] = val;
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
    int ids[] = {13, 7, 4, 1, 6, 8, 10};
    for (int i = 0; i < 7; i++)
    {
        q.enqueue(ids[i]);
    }
    q.dequeue();
    q.display();
    return 0;
}
