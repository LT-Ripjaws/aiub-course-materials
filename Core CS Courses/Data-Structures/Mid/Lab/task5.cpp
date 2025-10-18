#include <iostream>
using namespace std;
int main()
{
    int a[10][10], b[10][10], sub[10][10], i, j, m, n;
    cout << "Enter the number of rows and columns of matrix: ";
    cin >> m >> n;
    cout << "Enter the elements of first matrix: ";
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    cout << "Enter the elements of second matrix: ";
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> b[i][j];
    cout << "The subtraction of two matrices is: " << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
