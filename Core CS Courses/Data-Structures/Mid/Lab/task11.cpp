#include <iostream>
#include <string>

using namespace std;

string Encode(string s, int j)
{
    for (int i = j; i < s.length(); i += j + 1)
    {
        s[i] += 2;
    }
    return s;
}

int main()
{
    string input;
    int n;
    cout << "Enter a string: ";
    getline(cin, input);
    cout << "Enter a number: ";
    cin >> n;
    string encoded = Encode(input, n);
    cout << "Encoded string: " << encoded << endl;
    return 0;
}

