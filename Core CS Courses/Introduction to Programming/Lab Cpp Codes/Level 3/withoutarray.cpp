#include<iostream>
using namespace std;


int main()
{
    int marks1,marks2,marks3;
    float average;
    cout<<"Enter marks for 1st student : ";
    cin>>marks1;
    cout<<"Enter marks for 2nd student : ";
    cin>>marks2;
    cout<<"Enter marks for 3rd student : ";
    cin>>marks3;
    average = (marks1+marks2+marks3)/3.0;
    cout<<"Average Marks : "<<average<<endl;
    return 0;
}
