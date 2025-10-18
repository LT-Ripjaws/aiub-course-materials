#include <iostream>
using namespace std;

class Sample
{
   static int A;
   static int B;
   public:
   static void printValues(){
      A++;
      ++B;
      cout <<"Value of A: " << A << endl;
      cout <<"Value of B: " << B << endl;
   }
};
int Sample :: A=10;
int Sample :: B=20;

int main(){
   Sample s1;
   s1.printValues();
   return 0;
}
