#include<iostream>
using namespace std;

int rows;
const int MAXSIZE = 3;

class TwoDArray
{
public:
    void ArrayInsertion(int arr[][MAXSIZE]);
    void ArrayDisplay(int arr[][MAXSIZE]);
    void SumOfAllElements(int arr[][MAXSIZE]);
    void MaxMin(int arr[][MAXSIZE]);
    void SearchElement(int arr[][MAXSIZE]);
    void NumberOfOddEven(int arr[][MAXSIZE]);
    void Transpose(int arr[][MAXSIZE]);
};

void TwoDArray::ArrayInsertion(int arr[][MAXSIZE])
{
    cout<<"-------------------"<<endl;
    cout<<"Enter The Elements inside the Array"<<endl;
    cout<<"-------------------"<<endl;
    for(int i = 0; i<rows ; i++)
    {
        for(int j = 0; j<MAXSIZE; j++)
        {
            cout<<"\nRow "<<i<<" column "<<j<<" : ";
            cin>>arr[i][j];
        }
    }
    cout<<"-------------------\n"<<endl;
}

void TwoDArray::ArrayDisplay(int arr[][MAXSIZE])
{
    cout<<"-------------------"<<endl;
    cout<<"Display of the Array:"<<endl;
    cout<<"-------------------"<<endl;
    for(int i = 0; i<rows ; i++)
    {
        cout<<"\n      ";
        for(int j = 0; j<MAXSIZE; j++)
        {
            cout<<" ";
            cout<<arr[i][j];
        }
    }
    cout<<"\n\n-------------------\n"<<endl;
}


void TwoDArray::SumOfAllElements(int arr[][MAXSIZE])
{
    int sum = 0;
    cout<<"-------------------"<<endl;
    cout<<"The Sum of All Elements are :"<<endl;
    cout<<"-------------------"<<endl;
    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<MAXSIZE;j++)
            sum += arr[i][j];
    }
    cout<<"Sum : "<<sum<<endl;
    cout<<"-------------------\n"<<endl;
}

void TwoDArray::MaxMin(int arr[][MAXSIZE])
{
    int Maximum = 0;
    int Minimum = arr[rows][MAXSIZE];
    cout<<"-------------------"<<endl;
    cout<<"MAXMIN Function: "<<endl;
    cout<<"-------------------"<<endl;
    for (int i = 0;i<rows;i++)
    {
        for(int j = 0; j<MAXSIZE;j++)
        {
            if(Maximum<arr[i][j])
            Maximum=arr[i][j];
        }
    }
    for (int i = 0;i<rows;i++)
    {
        for(int j = 0; j<MAXSIZE;j++)
        {
            if(Minimum>arr[i][j])
            Minimum=arr[i][j];
        }
    }
    cout<<"The Maximum Number in Array is :"<<Maximum<<endl;
    cout<<"The Minimum Number in Array is :"<<Minimum<<endl;
    cout<<"-------------------\n"<<endl;
}

void TwoDArray::SearchElement(int arr[][MAXSIZE])
{
    int Null=0;
    int item,i,j;
    cout<<"-------------------"<<endl;
    cout<<"Search Function:"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Enter the Element to be searched : ";
    cin>>item;

    for( i=0;i<rows;i++)
    {
        for( j = 0;j<MAXSIZE;j++)
        {
            if(item == arr[i][j])
             {
                cout<<"The Number "<<item<<" is at row "<<i<<" column "<<j<<" "<<endl;
                break;
             }
            else
            {
                (item != arr[i][j]);
                Null++;
            }
        }
    }

    if(Null == (rows*MAXSIZE))
        cout<<"Not Present in this Array"<<endl;
    cout<<"-------------------\n"<<endl;
}

void TwoDArray::NumberOfOddEven(int arr[][MAXSIZE])
{
    int odd = 0;
    int even = 0;
    int i = 0;
    cout<<"-------------------"<<endl;
    cout<<"Numbers of Odd & Even Function:"<<endl;
    cout<<"-------------------"<<endl;
    for (i;i<rows;i++)
    {
        for(int j=0;j<MAXSIZE;j++)
        {
            if(arr[i][j]%2!=0)
                odd++;
            else even++;
        }
    }
    cout<<"There are "<<odd<<" odd and "<<even<<" even numbers in this Array. "<<endl;
    cout<<"-------------------\n"<<endl;
}

void TwoDArray::Transpose(int arr[][MAXSIZE])
{
    int transposed_arr[rows][MAXSIZE];
    cout<<"-------------------"<<endl;
    cout<<"MATRIX TRANSPOSED"<<endl;
    for(int i = 0;i<rows;++i)
    {
        for(int j=0;j<MAXSIZE;++j)
        {
            transposed_arr[j][i]=arr[i][j];
        }
    }
    for(int i = 0;i<MAXSIZE;++i)
    {
        for(int j=0;j<rows;++j)
        {
            cout<<transposed_arr[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<"-------------------\n"<<endl;
}

int main()
{
    int Matrix[0][MAXSIZE];
    cout<<"Welcome to 2D Array or Matrix Demo"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Enter Row Size : ";
    cin>>rows;

    TwoDArray A1;

    A1.ArrayInsertion(Matrix);
    A1.ArrayDisplay(Matrix);
    A1.SumOfAllElements(Matrix);
    A1.MaxMin(Matrix);
    A1.SearchElement(Matrix);
    A1.NumberOfOddEven(Matrix);
    A1.Transpose(Matrix);
    return 0;
}
