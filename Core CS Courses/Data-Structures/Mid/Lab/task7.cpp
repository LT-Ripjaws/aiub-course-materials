#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cout << "Enter the number of rows in the matrix: ";
    cin >> a;
    cout << "Enter the number of columns in the matrix: ";
    cin >> b;

    int matrix[a][b];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Traversing the matrix:" << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
