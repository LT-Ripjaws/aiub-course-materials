#include <iostream>

using namespace std;

int main()
{
    int A[10][10], B[10][10], multiply[10][10];
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter the number of rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter the number of columns for matrix A: ";
    cin >> colsA;

    cout << "Enter the number of rows for matrix B: ";
    cin >> rowsB;
    cout << "Enter the number of columns for matrix B: ";
    cin >> colsB;

    // this is to check if matrix multiplication is possible
    if (colsA != rowsB)
    {
        cout << "Matrix multiplication is not possible!" << endl;
        return 0;
    }


    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cin >> A[i][j];
        }
    }


    cout << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cin >> B[i][j];
        }
    }


    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            multiply[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                multiply[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    cout << "Result of matrix multiplication:" << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << multiply[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
