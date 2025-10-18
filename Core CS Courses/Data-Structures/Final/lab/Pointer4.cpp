#include<iostream>
using namespace std;

void decrease(void *data, int psize){
  if ( psize == sizeof(char) ){
     char *pchar;
     pchar=(char*)data;
     --(*pchar);
  }
  else if (psize == sizeof(int)){
     int *pint;
     pint=(int*)data;
     --(*pint);
  }
}
int main() {
  char a = 'f';
  int b = 1000;
  decrease (&a,sizeof(a));
  decrease (&b,sizeof(b));
  cout << a << ", " << b << endl;
}

