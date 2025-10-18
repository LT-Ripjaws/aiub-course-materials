#include<iostream>
using namespace std;

int sum(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int div(int a,int b);

int sum(int a,int b)
{
    int result;
    result=a+b;
    return result;
}
int sub(int a,int b)
{
    int result;
    result=a-b;
    return result;
}
int mul(int a,int b)
{
    int result;
    result=a*b;
    return result;
}
int div(int a,int b)
{
    int result;
    result=a/b;
    return result;
}

int main()
{
    int a,b,result;
    cout<<"Enter two integer number        : ";
    cin>>a>>b;
    result = sum(a,b);
    cout<<endl<<"After sum (a+b) result is       : "<<result<<endl;
    result = sub(a,b);
    cout<<"After sub (a-b) result is       : "<<result<<endl;
    result = mul(a,b);
    cout<<"After mul (a*b) result is       : "<<result<<endl;
    result = div(a,b);
    cout<<"After div (a/b) result is       : "<<result<<endl;

    return 0;
}

/*int sum(int a,int b)
{
    int result;
    result=a+b;
    return result;
}
int sub(int a,int b)
{
    int result;
    result=a-b;
    return result;
}
int mul(int a,int b)
{
    int result;
    result=a*b;
    return result;
}
int div(int a,int b)
{
    int result;
    result=a/b;
    return result;
}*/
