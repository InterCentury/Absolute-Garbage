#include <iostream>
#include <conio.h>
using namespace std;

int main()
{

    int num2,num1,num4,num3,num5;

    num1 = 10;
    num2 = 40;
    num4 = 20;
    num3 = 5;
    num5 = 3;
    int sum = num1 + num2;
    cout<< "Sum             = "<<sum<<endl;

    int mul = num1 * num3;
    cout<< "Multiplication  = "<<mul<<endl;

    int sub = num2 - num1;
    cout<< "Subtraction     = "<<sub<<endl;

    int div = num2 / num1;
    cout<< "Division        = "<<div<<endl;

    double rem =(float) num2 / num5;
    cout<< "Remainder       = "<<rem;



    getch();



}
