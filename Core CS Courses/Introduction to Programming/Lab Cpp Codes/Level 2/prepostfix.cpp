#include<iostream>
using namespace std;

int main ()
{
    int i,j;
    i=5;
    j=i++;
   ///j=i++;
   ///1) j=i=5;
   ///2) i=5+1=6
    cout<<"Post Increment"<<endl;
    cout<<"Value for i is : "<<i<<endl;
    cout<<"Value for j is : "<<j<<endl;

    j=++i;
   ///j=++i;
   ///1) i=5+1=6;
   ///2) j=i=6
    cout<<"Pre Increment"<<endl;
    cout<<"Value for i is : "<<i<<endl;
    cout<<"Value for j is : "<<j<<endl;


return 0;
}
