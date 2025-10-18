#include<iostream>
using namespace std;


int main()
{
    int i,n,arr1[100],arr2[100];
    cout<<endl<<endl<<"Copy n elements one array into another array : "<<endl;
    cout<<"==========================================================="<<endl;
    cout<<"Enter number of elements in the array : ";
    cin>>n;
    cout<<"Enter "<<n<< " elements in the array : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Element -- "<<i<<" : ";
        cin>>arr1[i];
    }

    ///Copy elements from array1 to array2
     for(i=0;i<n;i++)
    {
        arr2[i]=arr1[i];
    }
    cout<<endl<<"Elements stored in the first array : "<<endl;
        for(i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl<<"Elements stored in the Second array : "<<endl;
        for(i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}

