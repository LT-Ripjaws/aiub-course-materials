#include<iostream>
using namespace std;

/* Swap two numbers using function. */
void swap(int *a, int *b);

int main(){
  int num1=44,num2=33;
  swap(&num1,&num2);
  /* address of num1, num2 is passed */
  cout<<"Number1 = "<<num1<<"\n";
  cout<<"Number2 = "<<num2;
}
void swap(int *a, int *b){
//a,b points to &num1,&num2 respectively
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

