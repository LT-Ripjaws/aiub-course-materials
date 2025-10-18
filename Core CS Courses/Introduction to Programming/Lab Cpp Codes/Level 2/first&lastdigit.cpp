#include<iostream>
using namespace std;


int main()
{
    int num,lastnum;
    cout<<"Enter any number : ";
    cin>>num;

    lastnum=num%10;
    cout<<"The last number is "<<lastnum<<endl;

    while(num>10)
    {
        num=num/10;
    }
    cout<<"The first number is "<<num<<endl;
    return 0;
}
