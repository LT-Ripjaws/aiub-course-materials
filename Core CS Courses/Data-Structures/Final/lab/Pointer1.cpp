#include<iostream>
using namespace std;

int main()
{
 int a = 99;
 int *p = &a;
 int b = *p;
 cout <<"Address of integer variable a: "<< (uintptr_t) &a <<"\n";
 cout <<"Value stored in the memory area of a: "<< a <<"\n";
 cout <<"Address of integer pointer variable *p: "<< (uintptr_t) &p <<"\n";
 cout <<"Address stored in the area of pointer *p: "<< (uintptr_t) p<<"\n";
 cout <<"Address of integer variable b: "<< (uintptr_t) &b <<"\n";
 cout <<"Value pointed to by the pointer *p: "<< *p <<"\n";
 cout <<"Value stored in the memory area of variable b: "<< b <<"\n";
}

