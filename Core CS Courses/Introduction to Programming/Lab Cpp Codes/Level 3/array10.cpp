#include<iostream>
using namespace std;


int main()
{
    int arr[100];
    int i,mx,mn,n;
    cout<<"Find Minimum & Maximum value from an array : "<<endl;
    cout<<"============================================="<<endl;
    cout<<"Enter number of elements in the array : ";
    cin>>n;
    cout<<"Enter "<<n<< " elements in the array : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Element -- "<<i<<" : ";
        cin>>arr[i];
    }
    mx=arr[0];
    mn=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]>mx)
        {
            mx=arr[i];
        }
        if(arr[i]<mn)
        {
            mn=arr[i];
        }
    }
    cout<<"Maximum element is : "<<mx<<endl;
    cout<<"Minimum element is : "<<mn<<endl;
    return 0;
}
