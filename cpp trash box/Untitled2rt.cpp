#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    double radius, area, circumference;

    cout<<"enter the radius : ";
    cin>>radius;

    area = 3.1416 * radius * radius;

    circumference = 2 * 3.1416 * radius;

    cout<<"circle area is : " << area<<endl
    cout<<"circle circumference is : " <<circumference;

    getch();

}
