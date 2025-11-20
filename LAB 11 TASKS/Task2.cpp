#include <iostream>
using namespace std;
class Node
{
public:
    string word;
    string meaning;
    Node *next;

    Node(string w, string m)
    {
        word = w;
        meaning = m;
        next = nullptr;
    }
};
class Dictionary
{
private:
    Node *table[100];

    int hashFunction(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            sum += int(key[i]);
        }
        return sum % 100;
    }

public:
    Dictionary()
    {
        for (int i = 0; i < 100; i++)
            table[i] = nullptr;
    }

    void Add_Record(string word, string meaning)
    {
        int index = hashFunction(word);

        Node *temp = table[index];

        while (temp != nullptr)
        {
            if (temp->word == word)
            {
                temp->meaning = meaning;
                return;
            }
            temp = temp->next;
        }

        Node *newNode = new Node(word, meaning);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void Word_Search(string word)
    {
        int index = hashFunction(word);
        Node *temp = table[index];

        while (temp != nullptr)
        {
            if (temp->word == word)
            {
                cout << "search key " << word << ": " << temp->meaning << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Error! Word not found!" << endl;
    }

    void Delete_Record(string word)
    {
        int index = hashFunction(word);
        Node *temp = table[index];
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->word == word)
            {
                if (prev == nullptr)
                {
                    table[index] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }

                delete temp;
                cout << "key " << word << " deleted successfully!" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Word not found!" << endl;
    }

    void Print_Dictionary()
    {
        for (int i = 0; i < 100; i++)
        {
            cout << "index " << i << ": ";

            Node *temp = table[i];
            if (!temp)
            {
                cout << "EMPTY";
            }
            else
            {
                while (temp != nullptr)
                {
                    cout << "(" << temp->word << ", " << temp->meaning << ") ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Dictionary dict;

    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "DATA");

    dict.Word_Search("AB");

    dict.Delete_Record("EF");

    dict.Print_Dictionary();

    return 0;
}
