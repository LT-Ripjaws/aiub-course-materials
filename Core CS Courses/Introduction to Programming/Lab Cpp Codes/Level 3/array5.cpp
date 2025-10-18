#include<iostream>
using namespace std;


int main()
{
    int arr[10],i,sum=0,avg=0;
    cout<<"Enter 10 array Elements : "<<endl;
    for(i=0;i<10;i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
    cout<<"The array elements are : "<<endl;
    for(i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Sum of all elements are     : "<<sum<<endl;
    avg = sum/10;
    cout<<endl<<"Average of all elements are : "<<avg<<endl;
    return 0;
}
