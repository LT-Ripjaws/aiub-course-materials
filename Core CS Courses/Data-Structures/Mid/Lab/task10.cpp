#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 3, 6, 7, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool Unique = true;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < size - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
                Unique = false;
            }
        }
    }

    if (Unique)
    {
        cout << "Array already unique!" << endl;
    }
    else
    {
        cout << "Changed array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
