#include<iostream>
using namespace std;


int main()
{
    int arr[5],i;
    cout<<"Address of the elements of array : "<<endl;
    for(i=0;i<5;i++)
    {
        cout<<"Address for index "<<i<<" :"<<&arr[i]<<endl;
    }
    return 0;
}


