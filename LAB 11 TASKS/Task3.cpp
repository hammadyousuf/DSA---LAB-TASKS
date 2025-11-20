#include <iostream>
#include <list>
using namespace std;

class Hash
{
private:
    int size;
    list<int> *table;

    int hashFunction(int key)
    {
        return key % size;
    }

public:
    Hash(int s = 10)
    {
        size = s;
        table = new list<int>[size];
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        for (int x : table[index])
        {
            if (x == key)
            {
                return true;
            }
        }
        return false;
    }

    void Delete(int key)
    {
        int index = hashFunction(key);
        list<int>::iterator it;

        for (it = table[index].begin(); it != table[index].end(); it++)
        {
            if (*it == key)
            {
                table[index].erase(it);
                cout << key << " deleted successfully!" << endl;
                return;
            }
        }

        cout << "Key not found!" << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << ": ";
            for (int x : table[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Hash h(10);

    h.insert(15);
    h.insert(25);
    h.insert(35);

    h.display();

    cout << "\nSearching 25: " << (h.search(25) ? "Found" : "Not Found") << endl;

    h.Delete(25);

    h.display();

    return 0;
}
