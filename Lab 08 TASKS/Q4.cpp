#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    else
    {
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

bool search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    else
    {
        if (root->data == key)
        {
            return true;
        }
        else if (key < root->data)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int n, value;

    cout << "Enter number of nodes to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nEnter value to search: ";
    int key;
    cin >> key;

    if (search(root, key))
    {
        cout << key << " found in the BST." << endl;
    }
    else
    {
        cout << key << " not found. Inserting into the BST." << endl;
        root = insert(root, key);
    }

    cout << "\nUpdated BST (Inorder Traversal): ";
    inorder(root);
    cout << endl;

    return 0;
}
