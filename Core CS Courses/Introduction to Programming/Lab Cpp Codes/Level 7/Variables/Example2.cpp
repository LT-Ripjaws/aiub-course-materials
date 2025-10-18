#include <iostream>
using namespace std;

class Marks {

public:
    // This is a class variable
    static int studentNumber;

    // These variables are instance variables.
    // These variables are in a class
    // and are not inside any function
    int engMarks;
    int mathsMarks;
    int phyMarks;

public:
    Marks()
    {
        int con;

        // Modify the class variable
        ++studentNumber;
    };
};

// Setting the class variable of Marks
int Marks::studentNumber = 0;

// Driver code
int main()
{

    // first object
    Marks obj1;
    obj1.engMarks = 50;
    obj1.mathsMarks = 80;
    obj1.phyMarks = 90;

    // second object
    Marks obj2;
    obj2.engMarks = 80;
    obj2.mathsMarks = 60;
    obj2.phyMarks = 85;

    // displaying marks for first object
    cout << "Marks for first object:\n";
    cout << Marks::studentNumber << endl;
    cout << obj1.engMarks << endl;
    cout << obj1.mathsMarks << endl;
    cout << obj1.phyMarks << endl;

    // displaying marks for second object
    cout << "Marks for second object:\n";
    cout << Marks::studentNumber << endl;
    cout << obj2.engMarks << endl;
    cout << obj2.mathsMarks << endl;
    cout << obj2.phyMarks << endl;
}
