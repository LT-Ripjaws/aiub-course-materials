#include <iostream>
#include <string>

using namespace std;
class sample
{
   int num1,num2;

   void readNum(){
   cout<<"Enter num1 : "; cin>>num1;
   cout<<"\nEnter num2 : "; cin>>num2;
}

public:
void displaySum()
{
   readNum();
   cout<<"\nSum of the two numbers = "<<num1+num2<<endl;
}

};
int main()
{
   sample s;
   s.displaySum();
}
