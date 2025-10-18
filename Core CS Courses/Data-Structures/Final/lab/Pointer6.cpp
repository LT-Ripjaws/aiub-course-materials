#include<iostream>
using namespace std;

// arrays as parameters
void TwiceArray (int arg[], int length) {
  for (int n=0; n<length; n++) arg[n] *= 2;
}
void PrintArray(const int arg[], int length){
  for (int n=0; n<length; n++)
    cout<<arg[n];
  cout<<endl;
}
int main (int){
  int FirstArray[3] = {11, 22, 33};
  int SecondArray[] = {3, 5, 7, 9, 111};
  TwiceArray (FirstArray,3);
  PrintArray (FirstArray,3);
  PrintArray (SecondArray,5);
}

