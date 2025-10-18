#include <iostream>
using namespace std;

int main(){
   //Pointer declaration
   int *p;
   //Array declaration
   int arr[]={1, 2, 3, 4, 5, 6};
   //Assignment
   p = arr;
   for(int i=0; i<6;i++){
     cout<<*p<<endl;
     //++ moves the pointer to next int position
     p++;
   }
   return 0;
}
