#include <iostream>
using namespace std;
int binary_search(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
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
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[20] = {12, 45, 23, 67, 34, 89, 56, 90, 11, 78};
    int n = 10;
    insertion_sort(arr, n);
    cout << "Sorted array: {";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    int roll_number;
    cout << "Enter last two digits of your roll number: ";
    cin >> roll_number;

    int position = binary_search(arr, n, roll_number);

    if (position == -1)
    {
        arr[n++] = roll_number;
        insertion_sort(arr, n);
        cout << roll_number << " not found, inserted into array." << endl;
        position = binary_search(arr, n, roll_number);
    }
    cout << "Value " << roll_number << " found at index " << position << " (0-based)." << endl;
    cout << "Final array: {";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    return 0;
}
