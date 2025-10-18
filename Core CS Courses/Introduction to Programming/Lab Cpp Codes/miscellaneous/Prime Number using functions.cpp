#include<iostream>
using namespace std;

bool primeNumber(int n)
{
    bool isPrime = true;
    if (n == 0 || n == 1)
        isPrime = false;
    for (int i=2; i<=n/2; i++)
    {
        if (n%i==0)
            isPrime = false;
        break;
    }
    return isPrime;


}

int main()
{
    int n;
    cout<<"Please enter any number = ";
    cin>>n;
    if (primeNumber(n))
        cout<<n<<" is a prime";
    else
        cout<<n<<" is not a prime";
    return 0;
}
