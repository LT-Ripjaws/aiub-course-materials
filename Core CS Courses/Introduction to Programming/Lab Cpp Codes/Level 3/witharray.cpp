#include<iostream>
using namespace std;


int main()
{
    int marks[3];
    float average;
    cout<<"Enter marks for 1st student : ";
    cin>>marks[0];
    cout<<"Enter marks for 2nd student : ";
    cin>>marks[1];
    cout<<"Enter marks for 3rd student : ";
    cin>>marks[2];
    average = (marks[0]+marks[1]+marks[2])/3.0;
    cout<<"Average Marks : "<<average<<endl;
    return 0;
}

