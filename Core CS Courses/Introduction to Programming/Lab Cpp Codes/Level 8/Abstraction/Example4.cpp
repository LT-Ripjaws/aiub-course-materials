#include <iostream>
#include <string>

using namespace std;
class employee{
   int empId;
   string name;
   double salary,basic,allowances;

   double calculateSalary(int empId){
   salary = basic+allowances;
   return salary;
}
public:
employee(int empId, string name,double basic,double allowances):
empId(empId),name(name),basic(basic),allowances(allowances){
   calculateSalary(empId);
}

void display(){

   cout<<"EmpId = "<<empId<<"\tName = "<<name<<endl;
   cout<<"Employee Salary = "<<salary;

}
};
int main()
{
   employee emp(1,"Ved",15000,3245.43);
   emp.display();

}
