 #include<iostream>
 using namespace std;


 class Point
 {
 private:
    int x,y;
 public:
    /*Point(int x1,int y1)
    {
        x=x1;
        y=y1;
    }*/

    void setX(int x1)
    {
        x=x1;
    }
    void setY(int y1)
    {
        y=y1;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
 };

 int main()
 {
     ///Point p1(10,20);
     Point p1;
     p1.setX(10);
     p1.setY(20);
     cout<<"p1.x = "<<p1.getX()<<" p1.y = "<<p1.getY()<<endl;
     return 0;
 }
