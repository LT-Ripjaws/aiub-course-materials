#include<iostream>
using namespace std;


int main()
{
    int arr[100];
    int i,mx,mn,n;
    cout<<"Find all negative elements from an array : "<<endl;
    cout<<"============================================="<<endl;
    cout<<"Enter number of elements in the array : ";
    cin>>n;
    cout<<"Enter "<<n<< " elements in the array : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Element -- "<<i<<" : ";
        cin>>arr[i];
    }

    ///Finding negative elements
    cout<<"All negative elements in the array : ";
    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            cout<<arr[i]<<" ";
        }
    }
     return 0;
}
