#include <iostream>
#include <string>
using namespace std;

class Accounts{
   int empId;
   double salary, basic, allowances, deductions;
   public:
   Accounts(int empId){this->empId=empId;}
   void readEmployeeInfo(int empId){
      cout<<"Enter basic for the employee "<<empId<<":";
      cin>>basic;
      cout<<"allowances:";
      cin>>allowances;
      cout<<"deductions:";
      cin>>deductions;
   }
   double calculateSalary(){
      salary = basic+ allowances - deductions;
      return salary;
   }
   void display(){
   salary = calculateSalary();
   cout<<"Employee: "<<empId<<endl;
   cout<<"Salary: "<<salary;
   }
};
int main()
   {
       Accounts acc(1);
       acc.readEmployeeInfo(1);
       acc.display();
   }
