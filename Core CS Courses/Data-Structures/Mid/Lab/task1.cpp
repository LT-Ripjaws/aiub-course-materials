#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};

    cout << "Elements in normal order: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nElements in reverse order: ";
    for (int i = 9; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
