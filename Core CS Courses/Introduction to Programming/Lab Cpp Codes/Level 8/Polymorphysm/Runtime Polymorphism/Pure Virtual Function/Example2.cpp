#include<iostream>
using namespace std;

class B {
   public:
      virtual void s() = 0; // Pure Virtual Function
};

class D:public B {
   public:
      void s() {
         cout << "Virtual Function in Derived class\n";
      }
};

int main() {
   B *b;
   D dobj;
   b = &dobj;
   b->s();
}
