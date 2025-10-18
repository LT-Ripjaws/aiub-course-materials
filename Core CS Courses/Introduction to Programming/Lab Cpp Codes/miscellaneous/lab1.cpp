#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    string name;
};

class Student : public Person
{
protected:
    string faculty;
public:
    void setFaculty(string faculty)
    {
        this->faculty = faculty;
    }
    void displayStudentInfo()
    {
        cout<<"faculty = "<<faculty<<endl;
    }

};

class GradStudent : public Student
{
protected:
    double cgpa;
public:
    void setName1(string name)
    {
        this->name = name;
    }

    void getName1()
    {
        cout<<"Name = "<<name<<endl;
    }
    void setcpga(double x)
    {
        cgpa = x;
    }
    void getcpga()
    {
        cout<<"CGPA = "<<cgpa<<endl;
    }
};

int main()
{
    GradStudent ob1;
    ob1.setName1("Ansu");
    ob1.getName1();
    ob1.setFaculty("CSE");
    ob1.displayStudentInfo();
    ob1.setcpga(5.00);
    ob1.getcpga();
    return 0;
}
