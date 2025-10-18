#include <iostream>
using namespace std;

int start, end;

PrintOddNumbers(int x, int y)
{
    start = x;
    end = y;
    for (int i = start; i <= end; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << " ";
        }
    }
}


int main()
{
    int a, b;
    cout << "Enter starting value of the range: ";
    cin >> a;
    cout << "Enter ending value of the range: ";
    cin >> b;
    PrintOddNumbers(a,b);
    return 0;
}
