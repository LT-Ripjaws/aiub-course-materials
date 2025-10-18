#include <iostream>
using namespace std;

class Mammal {

public:
	virtual void eat() {

		cout << "Mammals eat...";
	}

};

class Cow: public Mammal {

public:
	void eat() {

		cout << "Cows eat grass...";
	}
};
int main(void) {

	///Cow c = Cow();
	///c.eat();

	/*Mammal *m;
	m= &c;
	m.eat();*/
	Mammal *c;
    Cow m;
	c=&m;
	c->eat();

	return 0;

}
