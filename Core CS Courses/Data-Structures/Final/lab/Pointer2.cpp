#include<iostream>
using namespace std;

int main()
{
 float r[5] = {12.5,24.8,36.8,49.1,58.3};
 cout<<"just r: "<< (uintptr_t) r <<"\n";
 cout<<"Address of Array using &r: "<< (uintptr_t) &r <<"\n";
 cout <<"1st element: "<< r[0] <<"\n";
 cout <<"1st element: "<< *r <<"\n";
 cout <<"3rd element: "<< r[2] <<"\n";
 cout <<"3rd element: "<< *(r+2)<<"\n";
 cout <<"1st element increment 1: "<< *r + 1 <<"\n";
 float *p;
 p = r; //&r[0]
 cout <<"1st element: "<< p[0] <<"\n";
 cout <<"1st element: "<< *p <<"\n";
 cout <<"3rd element: "<< p[2]<<"\n";
 cout <<"3rd element: "<< *(p+2)<<"\n";
 for(int i=0; i<5; i++, p++)
  cout <<"Element "<<(i+1)<<" is: "<<*p<<"\n";
}

