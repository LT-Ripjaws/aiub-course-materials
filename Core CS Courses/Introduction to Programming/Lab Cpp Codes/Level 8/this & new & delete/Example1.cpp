#include<iostream>
using namespace std;

class Vehicle
{
protected:
    string vehicleName;
    int vehicleSpeed;
    string vehicleColor;
public:
    Vehicle(string a,int b,string c)
    {
        this->vehicleName=a;
        this->vehicleSpeed=b;
        this->vehicleColor=c;
    }
    void vehicleMethod(void)
    {
        cout <<"Name of the Vehicle is " <<vehicleName<<endl;
        cout <<vehicleName <<"'s top speed = "<<vehicleSpeed<<" km/s"<<endl;
        cout <<vehicleName << " is " <<vehicleColor<<endl;
    }


};
class Car:public Vehicle
{
public:
    Car(string a,int b,string c):Vehicle(a,b,c){}
    void vehicleMethod(void)
    {
        cout <<"Name of the Car is " <<vehicleName<<endl;
        cout <<vehicleName <<"'s top speed = "<<vehicleSpeed<<" km/s"<<endl;
        cout <<vehicleName << " is " <<vehicleColor<<endl;
    }


};

class MotorBike:public Vehicle
{
public:
    MotorBike(string a,int b,string c):Vehicle(a,b,c){};
    void vehicleMethod(void)
    {
        cout <<"Name of the Motor Bike is " <<vehicleName<<endl;
        cout <<vehicleName <<"'s top speed = "<<vehicleSpeed<<" km/s"<<endl;
        cout <<vehicleName << " is " <<vehicleColor<<endl;
    }
};
class Bus:public Vehicle
{
public:
    Bus(string a,int b,string c):Vehicle(a,b,c){};
    void vehicleMethod(void)
    {
        cout <<"Name of the Bus is " <<vehicleName<<endl;
        cout <<vehicleName <<"'s top speed = "<<vehicleSpeed<<" km/s"<<endl;
        cout <<vehicleName << " is " <<vehicleColor<<endl;
    }
};
main()
{
    Vehicle *vehicleObj;
    Car *carObj;
    MotorBike *mBikeObj;
    Bus *busObj;

    vehicleObj = new Vehicle("Car",180,"White");
    carObj = new Car("BMW",220,"Blue");
    mBikeObj = new MotorBike("TVS",180,"Red");
    busObj = new Bus("Volvo",200,"Yellow");

    vehicleObj->vehicleMethod();
    carObj ->vehicleMethod();
    mBikeObj ->vehicleMethod();
    busObj ->vehicleMethod();


}

