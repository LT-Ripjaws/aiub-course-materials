#include <iostream>
using namespace std;

int main(){
   //Pointer declaration
   int *p, var=101;

   //Assignment
   p = &var;

   cout<<"Address of var: "<<&var<<endl;
   cout<<"Address of var: "<<p<<endl;
   cout<<"Address of p: "<<&p<<endl;
   cout<<"Value of var: "<<*p;
   return 0;
}
