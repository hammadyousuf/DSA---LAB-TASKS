#include <iostream>
using namespace std;

struct Node
{
    int productID;
    int quantity;
    Node *left;
    Node *right;

    Node(int id, int qty)
    {
        productID = id;
        quantity = qty;
        left = right = nullptr;
    }
};

class InventoryBST
{
private:
    Node *root;

    Node *insert(Node *node, int id, int qty)
    {
        if (node == nullptr)
        {
            return new Node(id, qty);
        }
        if (id < node->productID)
        {
            node->left = insert(node->left, id, qty);
        }
        else if (id > node->productID)
        {
            node->right = insert(node->right, id, qty);
        }
        else
        {
            node->quantity += qty;
        }
        return node;
    }

    Node *search(Node *node, int id)
    {
        if (node == nullptr || node->productID == id)
        {
            return node;
        }
        if (id < node->productID)
        {
            return search(node->left, id);
        }
        else
        {
            return search(node->right, id);
        }
    }

    void findMaxQuantity(Node *node, int &maximum_quantity, int &id)
    {
        if (node == nullptr)
            return;
        if (node->quantity > maximum_quantity)
        {
            maximum_quantity = node->quantity;
            id = node->productID;
        }
        findMaxQuantity(node->left, maximum_quantity, id);
        findMaxQuantity(node->right, maximum_quantity, id);
    }

public:
    InventoryBST()
    {
        root = nullptr;
    }

    void insertProduct(int id, int qty)
    {
        root = insert(root, id, qty);
    }

    void updateQuantity(int id, int qty)
    {
        Node *node = search(root, id);
        if (node != nullptr)
        {
            node->quantity += qty;
        }
        else
        {
            cout << "Product ID " << id << " not found. Inserting new product.\n";
            insertProduct(id, qty);
        }
    }

    void searchProduct(int id)
    {
        Node *node = search(root, id);
        if (node != nullptr)
        {
            cout << "Product ID: " << node->productID << ", Quantity: " << node->quantity << endl;
        }
        else
        {
            cout << "Product ID " << id << " not found.\n";
        }
    }

    void productWithMaxQuantity()
    {
        int maximum_quantity = -1;
        int id = -1;
        findMaxQuantity(root, maximum_quantity, id);
        if (id != -1)
        {
            cout << "Product with highest quantity -> ID: " << id << ", Quantity: " << maximum_quantity << endl;
        }
        else
        {
            cout << "Inventory is empty.\n";
        }
    }
};

int main()
{
    InventoryBST inventory;

    inventory.insertProduct(101, 50);
    inventory.insertProduct(102, 30);
    inventory.insertProduct(103, 70);

    inventory.updateQuantity(102, 25);
    inventory.updateQuantity(104, 40);

    inventory.searchProduct(103);
    inventory.searchProduct(105);

    inventory.productWithMaxQuantity();

    return 0;
}
