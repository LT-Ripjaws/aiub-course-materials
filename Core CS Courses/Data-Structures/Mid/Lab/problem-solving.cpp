#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        char input[80];
        cin >> input;
        int len = strlen(input);

        // Sort letters
        for (int j = 0; j < len; ++j)
        {
            for (int k = j + 1; k < len; ++k)
            {
                if (isalpha(input[j]) && isalpha(input[k]) && input[j] > input[k])
                {
                    swap(input[j], input[k]);
                }
            }
        }

        // Sort digits
        for (int j = 0; j < len; ++j)
        {
            for (int k = j + 1; k < len; ++k)
            {
                if (isdigit(input[j]) && isdigit(input[k]) && input[j] > input[k])
                {
                    swap(input[j], input[k]);
                }
            }
        }

        cout << input << endl;
    }

    return 0;
}
