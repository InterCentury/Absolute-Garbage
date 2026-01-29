#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
   float n1 , n2;

   cout << "Enter 2 number :";
   cin >> n1 >> n2;

   char op;
   cout << "Enter an operator :";
   cin >> op;

switch (op)

{

   case '+':
        cout << n1 + n2 ;
        break;

   case '-':
        cout  << n1 - n2 ;
        break;

  case '*':
        cout << n1 * n2 ;
        break;

  case '/':
        cout << n1 / n2;
        break;

 default :
        cout << "Enter valid Arithmetic operator !";
        break;

}
        getch();




}
