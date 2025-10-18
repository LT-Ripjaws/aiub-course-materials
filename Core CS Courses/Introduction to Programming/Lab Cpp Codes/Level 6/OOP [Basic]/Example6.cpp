#include<iostream>
using namespace std;


class test
{
private:
    int x;
public:
    test()
    {
        x=7;
    }
    test(int x1)
    {
        x=x1;
    }
    test(const test &t2)
    {
        x=t2.x;
    }
    int getX()
    {
        return x;
    }
};

int main()
{
  test t1(7);
  test t2=t1;///Copy constructor called
  cout<<"t1.x = "<<t1.getX()<<endl;///7
  cout<<"t2.x = "<<t2.getX()<<endl;///7
}
