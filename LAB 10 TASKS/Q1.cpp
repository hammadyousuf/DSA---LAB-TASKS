#include <iostream>
using namespace std;

void heapify_maximum(int arr[], int n, int i)
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
        heapify_maximum(arr, n, largest);
    }
}

void heapify_minimum(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest])
    {
        smallest = l;
    }
    if (r < n && arr[r] < arr[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify_minimum(arr, n, smallest);
    }
}

void build_maximum_heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify_maximum(arr, n, i);
    }
}

void build_minimum_heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify_minimum(arr, n, i);
    }
}

void update_key(int arr[], int n, int i, int new_val, bool isMax)
{
    arr[i] = new_val;
    if (isMax)
    {
        build_maximum_heap(arr, n);
    }
    else
    {
        build_minimum_heap(arr, n);
    }
}

void delete_key(int arr[], int &n, int i, bool isMax)
{
    arr[i] = arr[n - 1];
    n--;
    if (isMax)
    {
        heapify_maximum(arr, n, i);
    }
    else
    {
        heapify_minimum(arr, n, i);
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
    int arr1[] = {8, 7, 6, 5, 4};
    int n1 = 5;
    build_maximum_heap(arr1, n1);
    cout << "Max Heap: ";
    display(arr1, n1);

    int arr2[] = {8, 7, 6, 5, 4};
    int n2 = 5;
    build_minimum_heap(arr2, n2);
    cout << "Min Heap: ";
    display(arr2, n2);

    update_key(arr1, n1, 2, 10, true);
    cout << "Updated Max Heap: ";
    display(arr1, n1);

    delete_key(arr1, n1, 1, true);
    cout << "After Deletion (Max Heap): ";
    display(arr1, n1);
}
