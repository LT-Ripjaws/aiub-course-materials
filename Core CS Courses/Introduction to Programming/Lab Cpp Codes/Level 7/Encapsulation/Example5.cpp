#include <iostream>
using namespace std;

class Rectangle
{
	int length;
	int breadth;
	public:
		void setDimension(int l, int b)
		{
			length = l;
			breadth = b;
		}
		int getArea()
		{
			return length * breadth;
		}
};

int main()
{
	Rectangle rt;
	rt.setDimension(7, 4);
	cout << rt.getArea() << endl;
	return 0;
}
