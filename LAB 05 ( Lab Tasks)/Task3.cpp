#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
int length_tail_rec(Node *node, int count = 0)
{
    if (node == NULL)
    {
        return count;
    }
    return length_tail_rec(node->next, count + 1);
}
int main()
{
    Node *head = new Node(40);
    head->next = new Node(75);
    head->next->next = new Node(34);
    cout << "Length of list = " << length_tail_rec(head) << endl;
    return 0;
}
