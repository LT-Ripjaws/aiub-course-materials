#include<iostream>
using namespace std;

int largest(int arr[], int numberofelement)
{
    int largest_value, i;
    largest_value = arr[0];
    for (i=1 ; i < numberofelement ; ++i)
    if (arr[i] > largest_value)
        largest_value = arr[i];
    return largest_value;
}

int main()
{
    int arr[100], n, i;
    cout<<"Please Enter Size of Array = ";
    cin>>n;
    for (i=0 ; i < n ; ++i)
    {
        cout<<"Element number "<<i<<" = ";
        cin>>arr[i];
    }
    cout<<"The Largest element is = "<<largest(arr,n)<<endl;
    return 0;
}

