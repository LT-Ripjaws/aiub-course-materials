#include<iostream>
using namespace std;

class Array
{
public:
    void ArrayInsertion(int arr[], int sizeofarray);
    void DisplayArray(int arr[], int sizeofarray);
    void SumOfAllElements(int arr[], int sizeofarray);
    void MaxMin(int arr[], int sizeofarray);
    void SearchElement(int arr[], int sizeofarray, int SearchItem);
    void NumberOfOddEven(int arr[], int size);
    void EvenOdd(int arr[], int size);
    void InsertionDeletion(int arr[], int size);
};

void Array::ArrayInsertion(int arr[],int Size)
{
    cout<<"Please Enter "<<Size<<" elements into the array."<<endl;
    for (int i = 0; i<Size; i++)
    {
        cout<<"Element No. "<<i + 1<<" : ";
        cin>>arr[i];
    }
}

void Array::DisplayArray(int arr[], int sizeofarray)
{
    cout<<"Elements of Array are : "<<endl;
    for(int i = 0;i<sizeofarray;i++)
    {
        cout<<arr[i]<<endl;
    }
}

void Array::SumOfAllElements(int arr[], int sizeofarray)
{
    int sum = 0;
    cout<<"The Sum of All Elements are :"<<endl;
    for (int i=0;i<sizeofarray;i++)
    {
        sum += arr[i];
    }
    cout<<"Sum : "<<sum<<endl;
}

void Array::MaxMin(int arr[], int sizeofarray)
{
    int Maximum = 0;
    int Minimum = arr[sizeofarray];
    for (int i = 0;i<sizeofarray;i++)
    {
        if(Maximum<arr[i])
            Maximum=arr[i];
    }
    for (int i = 0;i<sizeofarray;i++)
    {
        if(Minimum>arr[i])
        Minimum=arr[i];
    }
    cout<<"The Maximum Number in Array is :"<<Maximum<<endl;
    cout<<"The Minimum Number in Array is :"<<Minimum<<endl;
}

void Array::SearchElement(int arr[], int sizeofarray, int SearchItem)
{
    int Null=0;
    int i = 0;
    for (i;i<sizeofarray;i++)
    {
        if(SearchItem == arr[i])
            cout<<"The item you searched was found at index : "<<i<<endl;
        else if (SearchItem != arr[i])
            Null++;
    }
    if(Null==i)
        cout<<"Not Present in this Array"<<endl;
}

void Array::NumberOfOddEven(int arr[], int size)
{
    int odd = 0;
    int even = 0;
    int i = 0;
    for (i;i<size;i++)
    {
        if(arr[i]%2!=0)
            odd++;
        else even++;
    }
    cout<<"There are "<<odd<<" odd and "<<even<<" even numbers in this Array. "<<endl;
}

void Array::EvenOdd(int arr[], int size)
{
    for(int i = 0; i<size;i++)
    {
        if(arr[i]%2!=0)
        {
            cout<<"Odd Number : "<<arr[i]<<endl;
        }
        else cout<<"Even Number :"<<arr[i]<<endl;
    }
}

void Array::InsertionDeletion(int arr[], int size )
{
    int i = 0;
    cout<<"Enter Value to add at the end of Array :"<<endl;
    cin>>arr[size++];
    cout<<"Enter Value to add at the First index of Array :"<<endl;
    for(i=size;i>0;i--)
        arr[i]=arr[i-1];
    cin>>arr[0];size++;
    cout<<"Your new array is "<<endl;
    for (i=0;i<size;i++)
        cout<<arr[i]<<endl;
    cout<<"Deleted Value at first index."<<endl;
    for(i=0;i<size;i++)
        arr[i]=arr[i+1];
    size--;
    cout<<"Deleted value at end of Array."<<endl;
    size--;
    cout<<"Your new array is "<<endl;
    for (i=0;i<size;i++)
        cout<<arr[i]<<endl;
}


int main()
{
    int Arr[100],Max_size, item = 0;
    cout<<"Please write array size :";
    cin>>Max_size;
    cout<<endl;
    Array A1;
    cout<<"Insertion of Array: "<<endl;
    cout<<"-------------------"<<endl;
    A1.ArrayInsertion(Arr,Max_size);
    cout<<"-------------------\n"<<endl;

    cout<<"Display of All ELEMENTS: "<<endl;
    cout<<"-------------------"<<endl;
    A1.DisplayArray(Arr,Max_size);
    cout<<"-------------------\n"<<endl;

    cout<<"Sum of All ELEMENTS: "<<endl;
    cout<<"-------------------"<<endl;
    A1.SumOfAllElements(Arr,Max_size);
    cout<<"-------------------\n"<<endl;

    cout<<"Max/Min of All ELEMENTS: "<<endl;
    cout<<"-------------------"<<endl;
    A1.MaxMin(Arr,Max_size);
    cout<<"-------------------\n"<<endl;

    cout<<"Search Function: "<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Enter item to be searched :";
    cin>>item;
    A1.SearchElement(Arr,Max_size,item);
    cout<<"-------------------\n"<<endl;

    cout<<"Number of odd/even: "<<endl;
    cout<<"-------------------"<<endl;
    A1.NumberOfOddEven(Arr,Max_size);
    cout<<"-------------------\n"<<endl;

    cout<<"Those Odd/even Numbers: "<<endl;
    cout<<"-------------------"<<endl;
    A1.EvenOdd(Arr,Max_size);
    cout<<"-------------------\n"<<endl;

    cout<<"Insert/Delete Function: "<<endl;
    cout<<"-------------------"<<endl;
    A1.InsertionDeletion(Arr,Max_size);
    cout<<"-------------------"<<endl;

}
