 #include<iostream>
 using namespace std;


 class Cube
 {
 public:
    int side;
    Cube(int x)
    {
        side=x;
    }
    void display(){cout<<"Hello World"<<endl;}
 };
 int main()
 {
     Cube c1(5);
     Cube c2(6);
     Cube c3(7);

     cout<<c1.side;
     cout<<c2.side;
     cout<<c3.side<<endl;

     c1.display();
     c2.display();
     c3.display();
 }
