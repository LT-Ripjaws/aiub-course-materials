#include <iostream>
using namespace std;

class Demo
{   private://static data members
		static int X;
		static int Y;
	public:
	static void  Print()
	{
		cout <<"Value of X: " << X << endl;
		cout <<"Value of Y: " << Y << endl;
	}
};
int Demo :: X =10;
int Demo :: Y =20;
int main()
{   Demo OB;
	cout<<"Printing through object name:"<<endl;
	OB.Print();
	cout<<"Printing through class name:"<<endl;
	Demo::Print();
	return 0;
}
