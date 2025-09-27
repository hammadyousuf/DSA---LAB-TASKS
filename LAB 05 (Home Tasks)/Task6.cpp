#include <iostream>
using namespace std;
int recursiveArraySum(void *arr, int sizes[], int dimension)
{
    int sum = 0;

    if (dimension == 1)
    {
        int *array1D = (int *)arr;
        for (int i = 0; i < sizes[0]; i++)
        {
            sum = sum + array1D[i];
        }
    }
    else
    {
        void **array = (void **)arr;
        for (int i = 0; i < sizes[0]; i++)
        {
            sum = sum + recursiveArraySum(array[i], sizes + 1, dimension - 1);
        }
    }

    return sum;
}

int main()
{
    int *jagged[3];

    jagged[0] = new int[3]{15, 36, 45};
    jagged[1] = new int[2]{4, 20};
    jagged[2] = new int[4]{10, 1, 13, 78};

    int sizesRow1[] = {3};
    int sizesRow2[] = {2};
    int sizesRow3[] = {4};

    int total = 0;
    total = total + recursiveArraySum(jagged[0], sizesRow1, 1);
    total = total + recursiveArraySum(jagged[1], sizesRow2, 1);
    total = total + recursiveArraySum(jagged[2], sizesRow3, 1);

    cout << "Sum of all elements = " << total << endl;

    delete[] jagged[0];
    delete[] jagged[1];
    delete[] jagged[2];

    return 0;
}
