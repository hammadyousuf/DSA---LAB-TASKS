#include <iostream>
using namespace std;
void sort_birthyears(int arr[], int n)
{
    int count_2022 = 0, count_2023 = 0, count_2024 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 2022)
        {
            count_2022++;
        }
        else if (arr[i] == 2023)
        {
            count_2023++;
        }
        else if (arr[i] == 2024)
        {
            count_2024++;
        }
    }
    int index = 0;
    for (int i = 0; i < count_2022; i++)
    {
        arr[index++] = 2022;
    }
    for (int i = 0; i < count_2023; i++)
    {
        arr[index++] = 2023;
    }
    for (int i = 0; i < count_2024; i++)
    {
        arr[index++] = 2024;
    }
}
int main()
{
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort_birthyears(arr, n);
    cout << "OUTPUT: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
