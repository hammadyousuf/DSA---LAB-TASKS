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
    if (n)
    {
        return n->height;
    }
    else
    {
        return 0;
    }
}

int getLeftHeight(Node *root)
{
    if (root && root->left)
    {
        return height(root->left);
    }
    else
    {
        return 0;
    }
}

int getRightHeight(Node *root)
{
    if (root && root->right)
    {
        return height(root->right);
    }
    else
    {
        return 0;
    }
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

    root->height = 1 + max(height(root->left), height(root->right));
    return root;
}

void inorder(Node *root, int arr[], int &idx)
{
    if (!root)
    {
        return;
    }

    inorder(root->left, arr, idx);
    arr[idx++] = root->key;
    inorder(root->right, arr, idx);
}

int main()
{
    Node *root = NULL;
    int vals[] = {34, 23, 78, 15, 45, 67, 89};

    for (int v : vals)
    {
        root = insert(root, v);
    }

    int arr[100];
    int idx = 0;

    inorder(root, arr, idx);

    int k = 3;
    cout << k << "rd Smallest: " << arr[k - 1] << endl;
    cout << k << "rd Largest: " << arr[idx - k] << endl;

    cout << "Left Subtree Height: " << getLeftHeight(root) << endl;
    cout << "Right Subtree Height: " << getRightHeight(root) << endl;

    return 0;
}
