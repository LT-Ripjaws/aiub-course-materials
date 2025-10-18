#include<iostream>
using namespace std;

double squareArea(double num)
{
    double result = num*num;
    return result;
}
double rectangleArea(double num1, double num2)
{
    double result = num1*num2;
    return result;
}
double triangleArea(double base, double height)
{
    double result = 0.5*base*height;
    return result;
}

int main()
{
    double num,base,height,a,b,result;

    cout<<"Enter side of Square = ";
    cin>>num;
    result = squareArea(num);
    cout<<"Area of Square is = "<<result<<endl;

    cout<<"Enter width and length of rectangle = ";
    cin>>a>>b;
    result = rectangleArea(a,b);
    cout<<"Area of Rectangle is = "<<result<<endl;

    cout<<"Enter base and height of Triangle = ";
    cin>>base>>height;
    result = triangleArea(base,height);
    cout<<"Area of Triangle is = "<<result<<endl;
    return 0;
}
