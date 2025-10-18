#include<iostream>
using namespace std;


int main()
{
    int i,num,sum=0;
    cout<<"Numbers between 100 & 130 which is divisible by 9 : "<<endl<<endl;
    num=100;
    do{
        if(num%9==0)
        {
            cout<<"Number divisible by 9 is : "<<num<<endl;
            sum=sum+num;
        }
        num++;
      }
    while(num<130);
    cout<<"Sum of all numbers divisible by 9 is : "<<sum<<endl;
    return 0;
}
