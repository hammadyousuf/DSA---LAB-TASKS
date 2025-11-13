#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    int height;
    Node(int val) : key(val), left(NULL), right(NULL), height(1) {}
};

int height(Node *n)
{
    return n ? n->height : 0;
}

int getBalance(Node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *root, int key)
{
    if (!root)
    {
        return new Node(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }
    if (balance < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int v : values)
    {
        root = insert(root, v);
    }

    root = insert(root, 55);

    cout << "Before Left Rotation on Root (Preorder): ";
    preorder(root);
    cout << endl;

    root = leftRotate(root);

    cout << "After Left Rotation on Root (Preorder): ";
    preorder(root);
    cout << endl;

    return 0;
}
