#include <iostream>
using namespace std;

class A
{
    public:
    void display()
    {
        std::cout << "Class A" << std::endl;
    }
};
class B
{
    public:
    void display()
    {
        std::cout << "Class B" << std::endl;
    }
};
class C : public A, public B
{
    public:
    void view()
    {
        B::display();
    }
};
int main()
{
    C c;
    c.A::display();
    c.view();
    return 0;
}
