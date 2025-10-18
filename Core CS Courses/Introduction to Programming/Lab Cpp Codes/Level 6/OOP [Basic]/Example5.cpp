#include<iostream>
using namespace std;


class A
{
public:
    A()
    {
        cout<<"I am a Constructor from A Class "<<endl;
    }
    ~A()
    {
        cout<<"I am a Destructor from A Class "<<endl;
    }
};

class B
{
public:
    B()
    {
        cout<<"I am a Constructor from B Class "<<endl;
    }
    ~B()
    {
        cout<<"I am a Destructor from B Class "<<endl;
    }
};
class C
{
public:
    C()
    {
        cout<<"I am a Constructor from C Class "<<endl;
    }
    ~C()
    {
        cout<<"I am a Destructor from C Class "<<endl;
    }
};

int main()
{
    A a;
    B b;
    C c;
    return 0;
}
