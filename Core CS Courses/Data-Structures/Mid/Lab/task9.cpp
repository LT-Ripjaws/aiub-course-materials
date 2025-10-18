#include <iostream>

using namespace std;

int main()
{
    int size1, size2;
    cout << "Enter size of first array: ";
    cin >> size1;
    int arrA[size1];
    cout << "Enter elements of first array:" << endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> arrA[i];
    }

    cout << "Enter size of second array: ";
    cin >> size2;
    int arrB[size2];
    cout << "Enter elements of second array:" << endl;
    for (int i = 0; i < size2; i++)
    {
        cin >> arrB[i];
    }

    int size3 = size1 + size2;
    int arrMERGED[size3];

    for (int i = 0; i < size1; i++)
    {
        arrMERGED[i] = arrA[i];
    }

    for (int i = 0; i < size2; i++)
    {
        arrMERGED[size1 + i] = arrB[i];
    }

    cout << "Merged array in reverse order:" << endl;
    for (int i = size3 - 1; i >= 0; i--)
    {
        cout << arrMERGED[i] << " ";
    }
    cout << endl;

    return 0;
}
