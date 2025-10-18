#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {2, 12, 6, 8, 16, 11, 13, 15, 17, 34};
    int no_of_even = 0;
    int no_of_odd = 0;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 == 0)
        {
            no_of_even++;
        }
        else
        {
            no_of_odd++;
        }
    }

    // print even and odd count
    cout << "Number of Even: " << no_of_even << endl;
    cout << "\nNumber of Odd: " << no_of_odd << endl;

    return 0;
}

