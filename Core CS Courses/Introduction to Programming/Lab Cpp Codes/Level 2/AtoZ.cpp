#include<iostream>
using namespace std;


int main()
{
    int character = 0;
    char ch = 'A';
    do
    {
        character = ch;///ASCII 65 66
        cout<<ch<<" ";
        character++;///66
        ch=character;///B
    }
    while(ch<='Z');
    return 0;
}
