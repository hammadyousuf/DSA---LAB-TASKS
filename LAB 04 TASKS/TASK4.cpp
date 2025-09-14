#include <iostream>
using namespace std;
bool contain_duplicate(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {5, 3, 8, 2, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (contain_duplicate(arr, n))
    {
        cout << "Array contains duplicates." << endl;
    }
    else
    {
        cout << "Array does not contain duplicates." << endl;
    }
    return 0;
}
