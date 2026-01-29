#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int main()
{
    float num1,num2,num3,num4;






    cout<< " Enter 4 number  : ";
    cin>>num1>>num2>>num3>>num4;




    cout<<showpoint;
    cout<<setprecision(20);
    float sum = num1 + num2;
    cout<<setw(15)<<"sum = "<<sum<<endl;


    cout<<showpoint;
    cout<<setprecision(20);
    float sub = num1 - num3;
    cout<<setw(15)<< "Substraction = "<<sub<<endl;



    cout<<showpoint;
    cout<<fixed;
    cout<<setprecision(20);
    float div = num1 / num4;
    cout<<setw(15)<< "Division = "<<div<<endl;



    cout<<showpoint;
    cout<<setprecision(12);
    float mul = num1 * num2;
    cout<<setw(15)<<"Multiplication = "<<mul<<endl;


    cout<<showpoint;
    cout<<setprecision(20);
    int rem = num1 / num2;
    cout<<setw(15)<<"Remainder = "<<rem;


    getch();



}
