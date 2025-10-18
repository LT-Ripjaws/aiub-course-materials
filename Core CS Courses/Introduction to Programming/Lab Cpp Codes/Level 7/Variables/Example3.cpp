#include <iostream>
using namespace std;

class Marks {
public:
   ///static int studentNumber;
    int studentNumber=0;
    int engMarks;
    int mathsMarks;
    int phyMarks;

    Marks()
    {
        ++studentNumber;
    }
};
///int Marks::studentNumber = 0;
int main()
{   Marks obj1;
    Marks obj2;
    Marks obj3;
    obj1.engMarks = 50;
    obj1.mathsMarks = 80;
    obj1.phyMarks = 90;
    cout << "Marks for object:\n";
    ///cout << Marks::studentNumber << endl;
    cout << obj1.studentNumber << endl;
    cout << obj2.studentNumber << endl;
    cout << obj3.studentNumber << endl;
    cout << obj1.engMarks << endl;
    cout << obj1.mathsMarks << endl;
    cout << obj1.phyMarks << endl;
}
