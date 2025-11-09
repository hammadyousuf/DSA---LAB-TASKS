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

int countNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void findMedianUtil(Node *root, int &count, int n, int &median1, int &median2)
{
    if (root == nullptr)
    {
        return;
    }

    findMedianUtil(root->left, count, n, median1, median2);
    count++;

    if (n % 2 != 0)
    {
        if (count == (n + 1) / 2)
        {
            median1 = root->data;
        }
    }
    else
    {
        if (count == n / 2)
        {
            median1 = root->data;
        }
        if (count == n / 2 + 1)
        {
            median2 = root->data;
        }
    }

    findMedianUtil(root->right, count, n, median1, median2);
}

double findMedian(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int n = countNodes(root);
    int count = 0;
    int median1 = 0, median2 = 0;

    findMedianUtil(root, count, n, median1, median2);

    if (n % 2 != 0)
    {
        return median1;
    }
    else
    {
        return (median1 + median2) / 2.0;
    }
}

int main()
{
    Node *root = new Node(67);
    root->left = new Node(43);
    root->right = new Node(90);
    root->left->left = new Node(23);
    root->left->right = new Node(4);

    cout << "Median of BST: " << findMedian(root) << endl;

    return 0;
}
