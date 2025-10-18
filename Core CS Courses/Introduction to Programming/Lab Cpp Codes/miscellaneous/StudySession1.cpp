#include<iostream>

using namespace std;

int main()
{
    char ch;
    cout<<" Please Enter Any Alphabet to test = ";
    cin>>ch;
    switch (ch)
    {
    case 'a':
        cout<<ch<<" This is a vowel"<<endl;
        break;
    case 'e':
        cout<<ch<<" This is a vowel"<<endl;
        break;
    case 'i':
        cout<<ch<<" This is a vowel"<<endl;
        break;
    case 'o':
        cout<<ch<<" This is a vowel"<<endl;
        break;
    case 'u':
        cout<<ch<<" This is a vowel"<<endl;
        break;


        case 'A':
        cout<<ch<<" This is a vowel"<<endl;
        break;
        case 'E':
        cout<<ch<<" This is a vowel"<<endl;
        break;
        case 'I':
        cout<<ch<<" This is a vowel"<<endl;
        break;
        case 'O':
        cout<<ch<<" This is a vowel"<<endl;
        break;
        case 'U':
        cout<<ch<<" This is a vowel"<<endl;
        break;

        default:
            cout<<ch<<" This is not a vowel but a consonant"<<endl;
            break;
    }
    return 0;

    }

