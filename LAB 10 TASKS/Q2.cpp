#include <iostream>
using namespace std;

bool isHeap(int arr[], int n)
{
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left])
        {
            return false;
        }
        if (right < n && arr[i] < arr[right])
        {
            return false;
        }
    }
    return true;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {8, 7, 6, 5, 4};
    int n = 5;
    if (isHeap(arr, n))
    {
        cout << "Given array is a Max Heap" << endl;
    }
    else
    {
        cout << "Given array is not a Max Heap" << endl;
    }
    heapSort(arr, n);
    cout << "Array after sorting in ascending order: ";
    display(arr, n);
}
