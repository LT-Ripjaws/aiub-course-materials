#include<iostream>
using namespace std;

int main()
{
    char ch;
    cout<<"Enter an alphabet : ";
    cin>>ch;
    switch(ch)
    {
        case 'a':
        cout<<ch <<" is a vowel"<<endl;
        break;
        case 'e':
        cout<<ch <<" is a vowel"<<endl;
        break;
        case 'i':
        cout<<ch <<" is a vowel"<<endl;
        break;
        case 'o':
        cout<<ch <<" is a vowel"<<endl;
        break;
        case 'u':
        cout<<ch <<" is a vowel"<<endl;
        break;

        case 'A':
        cout<<ch <<" is a vowel"<<endl;
        break;
        case 'E':
        cout<<ch <<" is a vowel"<<endl;
        break;
        case 'I':
        cout<<ch <<" is a vowel"<<endl;
        break;
        case 'O':
        cout<<ch <<" is a vowel"<<endl;
        break;
        case 'U':
        cout<<ch <<" is a vowel"<<endl;
        break;

        default:
        cout<<ch <<" is a consonant"<<endl;
        break;
    }
        return 0;
}
