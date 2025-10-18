#include<iostream>
#include<conio.h>
using namespace std;

class Person
{
public:
    string name;
    int age, height;

    string setname(string x)
    {
        name = x;
    }
    string getname()
    {
        cout<<name;
    }
};

class Employee : public Person
{
protected:
   int empId, salary;
};

class Student : public Person
{

};

class graduateStudent : Student
{

};

class Officer : Employee
{

};

class faculty : Employee
{


};




int main()
{
    Person p1;
    p1.setname("chinmoy");
    p1.getname();







    getch();
}
