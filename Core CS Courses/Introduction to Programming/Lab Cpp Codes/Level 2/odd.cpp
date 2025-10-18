#include<iostream>
using namespace std;


int main()
{
    int i,num,sum=0;
    cout<<"Enter the last number : ";
    cin>>num;
    cout<<"Odd numbers from 1 to  "<<num<<": ";
    for(i=1;i<=num;i+=2)///i+=2 is similar like i=i+2
    {
        cout<<i<<" ";
        sum+=i;///sum+=i; is similar like sum=sum+i
    }
    cout<<endl<<"Sum of all odd number between 1 to "<<num<<": "<<sum ;
    return 0;
}

