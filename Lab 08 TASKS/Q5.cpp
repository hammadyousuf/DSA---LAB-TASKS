#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isBST(Node *root, int minimum_value = -2147483648, int maximum_value = 2147483647)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data <= minimum_value || root->data >= maximum_value)
    {
        return false;
    }
    return isBST(root->left, minimum_value, root->data) && isBST(root->right, root->data, maximum_value);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(25);
    root->left->right = new Node(30);

    if (isBST(root))
    {
        cout << "The tree is a BST." << endl;
    }
    else
    {
        cout << "The tree is NOT a BST." << endl;
    }

    return 0;
}
