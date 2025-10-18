#include<iostream>
using namespace std;


int main()
{
    ///Capital letter
    char ch;
    for(ch='A';ch<='Z';ch++)
    {
        cout<<"ASCII Value of : "<<ch<<"="<<(int)ch<<endl;
    }
    ///Small letter
    for(ch='a';ch<='z';ch++)
    {
        cout<<"ASCII Value of : "<<ch<<"="<<(int)ch<<endl;
    }
        return 0;
}
