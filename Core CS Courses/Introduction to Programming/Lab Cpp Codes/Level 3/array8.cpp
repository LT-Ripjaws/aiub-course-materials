#include<iostream>
using namespace std;


int main()
{
    int i,n,arr[100],sum=0;
    cout<<endl<<endl<<"Read n number of values in array & Display Sum of array elements : "<<endl;
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
    for(i=0;i<n;i++)
    {
        sum = sum + arr[i];
    }
    cout<<endl<<"The sum of array elements : "<<sum<<endl;

    return 0;
}
