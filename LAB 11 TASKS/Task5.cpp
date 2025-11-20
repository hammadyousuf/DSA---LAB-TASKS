#include <iostream>
using namespace std;
class StudentRecord
{
public:
    int roll;
    string name;
    bool occupied;

    StudentRecord()
    {
        roll = -1;
        name = "";
        occupied = false;
    }
};
class StudentHashTable
{
private:
    StudentRecord table[15];
    int size = 15;

public:
    void InsertRecord(int roll, string name)
    {
        int index = roll % size;
        for (int attempt = 0; attempt < size; attempt++)
        {
            int newIndex = (index + attempt * attempt) % size;

            if (!table[newIndex].occupied)
            {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].occupied = true;
                cout << "Record inserted at index " << newIndex << endl;
                return;
            }
        }
        cout << "Hash Table is full, cannot insert!" << endl;
    }

    void SearchRecord(int roll)
    {
        int index = roll % size;
        for (int attempt = 0; attempt < size; attempt++)
        {
            int newIndex = (index + attempt * attempt) % size;

            if (table[newIndex].occupied && table[newIndex].roll == roll)
            {
                cout << "Record found: " << table[newIndex].name << endl;
                return;
            }
        }
        cout << "Record not found" << endl;
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].occupied)
            {
                cout << i << ": (" << table[i].roll << ", " << table[i].name << ")" << endl;
            }
            else
            {
                cout << i << ": EMPTY" << endl;
            }
        }
    }
};

int main()
{
    StudentHashTable ht;
    ht.InsertRecord(597, "Hammad");
    ht.InsertRecord(894, "Umer");
    ht.InsertRecord(629, "Ahmed");

    ht.SearchRecord(597);
    ht.SearchRecord(689);

    cout << endl
         << "Displaying Table:" << endl;
    ht.Display();
    return 0;
}
