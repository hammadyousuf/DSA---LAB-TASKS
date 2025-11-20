#include <iostream>
using namespace std;
class Pair
{
public:
    int a, b;
    bool used;

    Pair()
    {
        a = 0;
        b = 0;
        used = false;
    }
};

int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = 7;

    Pair hashTable[5000];

    for (int i = 0; i < 5000; i++)
    {
        hashTable[i].used = false;
    }

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (!hashTable[sum].used)
            {
                hashTable[sum].a = arr[i];
                hashTable[sum].b = arr[j];
                hashTable[sum].used = true;
            }
            else
            {
                Pair old = hashTable[sum];

                if (old.a != arr[i] && old.a != arr[j] &&
                    old.b != arr[i] && old.b != arr[j])
                {
                    cout << "(" << old.a << ", " << old.b << ") and (" << arr[i] << ", " << arr[j] << ")" << endl;

                    found = true;
                    break;
                }
            }
        }

        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        cout << "No pairs found" << endl;
    }
    return 0;
}
