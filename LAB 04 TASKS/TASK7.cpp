#include <iostream>
#include <string>
using namespace std;
int linearsearch(string arr[], int n, string key, int &steps)
{
    steps = 0;
    for (int i = 0; i < n; i++)
    {
        steps++;
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int binarysearch(string arr[], int n, string key, int &steps)
{
    int low = 0, high = n - 1;
    steps = 0;
    while (low <= high)
    {
        steps++;
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    string arr[10] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};
    int n = 10;
    string search_names[3] = {"Aftab", "Rizwan", "Tariq"};
    for (int i = 0; i < 3; i++)
    {
        string name = search_names[i];
        int steps_linear, steps_binary;
        int index_linear = linearsearch(arr, n, name, steps_linear);
        int indexBinary = binarysearch(arr, n, name, steps_binary);

        cout << "Searching for: " << name << endl;
        if (index_linear != -1)
        {
            cout << " Linear Search -> Found at index " << index_linear;
        }
        else
        {
            cout << " Linear Search -> Not Found";
        }
        cout << " | Steps = " << steps_linear << endl;

        if (indexBinary != -1)
        {
            cout << " Binary Search -> Found at index " << indexBinary;
        }
        else
        {
            cout << " Binary Search -> Not Found";
        }
        cout << " | Steps = " << steps_binary << endl;
        cout << endl;
    }
    return 0;
}
