#include <iostream>
using namespace std;
class Node
{
public:
    string key;
    string value;
    Node *next;

    Node(string k, string v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};
class HashTable
{
private:
    int size;
    Node **table;

    int hashFunction(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            sum += int(key[i]);
        }
        return sum % size;
    }

public:
    HashTable(int s = 10)
    {
        size = s;
        table = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }
    void insert(string key, string value)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key, value);

        newNode->next = table[index];
        table[index] = newNode;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << ": ";

            Node *temp = table[i];
            if (!temp)
            {
                cout << "EMPTY";
            }
            else
            {
                while (temp)
                {
                    cout << "(" << temp->key << ", " << temp->value << ") ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashTable myhash;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    cout << "\nDisplaying Hash Table:\n";
    myhash.display();

    return 0;
}
