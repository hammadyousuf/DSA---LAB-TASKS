#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int arr[n];
    cout << "Enter 10 elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    cout << "\nThe 4 minimum elements are:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
