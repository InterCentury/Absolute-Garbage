#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    double area,radious,cirumference;
    cout<< "Enter the redious  : ";
    cin>>radious;

    area =  3.14159265359* radious * radious;
    cirumference = 2 * 3.14159265359 * radious;

    cout<< "area = "<<area<<endl;
    cout<< "cirumference = "<<cirumference;


    getch();
}
