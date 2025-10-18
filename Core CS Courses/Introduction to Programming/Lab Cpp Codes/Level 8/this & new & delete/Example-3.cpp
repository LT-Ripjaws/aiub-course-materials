#include<iostream>
using namespace std;

class A
{
    protected:
    string name;
    string id;
    public:
   A(){cout<<"A constructor called"<<endl;}
   ~A(){cout<<"A destructor called"<<endl;}
};
class B:A
{
    public:
   B(){cout<<"B constructor called"<<endl;}
   ~B(){cout<<"B destructor called"<<endl;}
    void print(string n,string i)
   {
       name=n;
       id=i;
       cout<<"I am print"<<endl;
       cout<<"I am "<<name<<endl;
       cout<<"I am "<<id<<endl;
   }
};
int main()
{   B *b = new B();  /// B b;
    b->print("Mahub","152122");
    delete b;
}
