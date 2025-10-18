#include<iostream>
using namespace std;


int main()
{
    int i,n,arr[100];
    cout<<endl<<endl<<"Read n number of values in array & Display in reverse order : "<<endl;
    cout<<"=========================================================================="<<endl;
    cout<<"Enter number of elements in the array : ";
    cin>>n;
    cout<<"Enter "<<n<< "elements in the array : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Element -- "<<i<<" : ";
        cin>>arr[i];
    }
    cout<<endl<<"The values entered in the array : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"The values entered in the array in reverse : "<<endl;
    for(i=n-1;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    return 0;
}
