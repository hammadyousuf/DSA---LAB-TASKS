/*

Why AVL? Explain in just two lines.

1) AVL trees keep the tree height-balanced (difference of heights of left and right subtrees ≤ 1), ensuring O(log n) lookup, insertion, and deletion.
2)That height balance gives more predictable and faster worst-case performance than an unbalanced BST.

Given the BST (A and B) below, write a function to convert these BST into an AVL tree. The
function should take the root of the BST as input and perform the conversion. Write only the
conversion function, with no insertion logic needed. You may hard-code the given BST for this
task.

FOR BST(A):

BST(A) is left-heavy, so it requires a Right Rotation to become balanced.

Conversion Function (for BST A)
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

int height(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;     
    Node* t2 = x->right;   
    x->right = y;
    y->left = t2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

Node* convertBST_A_to_AVL(Node* root) {
    if (root == NULL) return NULL;

    root->left = convertBST_A_to_AVL(root->left);
    root->right = convertBST_A_to_AVL(root->right);

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        root = rightRotate(root);
    }

    return root;
}

int main() {
    Node* rootA = new Node(10);
    rootA->left = new Node(6);
    rootA->left->left = new Node(4);
    rootA->left->right = new Node(8);

    rootA = convertBST_A_to_AVL(rootA);
    cout << "Root of AVL (A): " << rootA->key << endl;
    return 0;
}

Explanation (BST A):

1)Initial BST:

      10 (y)
     /
    6 (x)
   / \
  4   8

2)Check Balance:

10 has balance = +2 (left-heavy)
Type = Left-Left case → Right Rotation

3)Rotation Details:

y = 10 (unbalanced node)
x = 6 (left child)
t2 = x->right = 8

Perform rotation:
x->right = y
y->left = t2

So after rotation:
     6
    / \
   4   10
       /
      8

4)Rotation Type: Right Rotation (LL case)

5)Node Returned: The function returns node x (key = 6), which becomes the new root of the balanced tree.

========================================================================================================

FOR BST(B):

This is right-heavy, so it requires a Left Rotation to balance.

Node* leftRotate(Node* x) {
    Node* y = x->right;    
    Node* t2 = y->left;   

    y->left = x;
    x->right = t2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

Node* convertBST_B_to_AVL(Node* root) {
    if (root == NULL) return NULL;

    root->left = convertBST_B_to_AVL(root->left);
    root->right = convertBST_B_to_AVL(root->right);

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    int balance = getBalance(root);

    if (balance < -1 && getBalance(root->right) <= 0) {
        root = leftRotate(root);
    }

    return root;
}

int main() {
    Node* rootB = new Node(10);
    rootB->right = new Node(16);
    rootB->right->left = new Node(12);
    rootB->right->right = new Node(18);

    rootB = convertBST_B_to_AVL(rootB);
    cout << "Root of AVL (B): " << rootB->key << endl;
    return 0;
}

Explanation (BST B):

1)Initial BST:

    10 (x)
      \
       16 (y)
      /  \
    12   18

2)Check Balance:
Node 10: balance = -2 (right-heavy)
Type = Right-Right case → Left Rotation

3)Rotation Details:
x = 10 (unbalanced node)
y = 16 (right child)
t2 = y->left = 12

Perform rotation:
y->left = x
x->right = t2

After rotation:
     16
    /  \
  10    18
    \
     12

4)Rotation Type: Left Rotation (RR case)

5)Node Returned: The function returns node y (key = 16), which becomes the new root of the balanced AVL tree.

*/