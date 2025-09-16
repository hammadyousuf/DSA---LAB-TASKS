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
bool search_non_tail(Node *node, int key)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->data == key)
    {
        return true;
    }
    return search_non_tail(node->next, key);
}
int main()
{
    Node *head = new Node(56);
    head->next = new Node(23);
    head->next->next = new Node(89);

    int key = 89;
    if (search_non_tail(head, key))
    {
        cout << key << " found in list" << endl;
    }
    else
    {
        cout << key << " not found in list" << endl;
    }
    return 0;
}
