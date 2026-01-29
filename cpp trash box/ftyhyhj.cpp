#include <iostream>
#include <conio.h>
using namespace std;
int main()
{   int n1,n2;
    cout << "for multiplication-table , press $ "<< endl<<endl;
    char op;
      cout << "select operator :";
      cin >> op;

      switch (op)
      {case '+' :

       cout << "Enter 1st number : ";
       cin >> n1;

       cout << "Enter 2nd number : ";
       cin >> n2;

       cout << n1 << op << n2 << " = "<< n1 + n2;
       break;

      case '-':
      cout << "Enter 1st number : ";
      cin >> n1 ;

      cout << "Enter 2nd number : ";
      cin >> n2 ;

      cout <<  n1 << op << n2 << " = "<< n1 - n2;
      break;

      case '*':
      cout << "Enter 1st number : ";
      cin >> n1;

      cout << "Enter 2nd number :";
      cin >> n2;

      cout <<  n1 << op << n2 << " = "<< n1 * n2;
      break;

      case '/':
      cout << "Enter 1st number : ";
      cin >> n1;

      cout << "Enter 2nd number : ";
      cin >> n2;

      cout << n1 << op << n2 << " = " << n1 / n2;
      break;

      case '$':

      int num,n0;
      cout << "Enter any number :";
      cin >> num;

      cout << "How many times do you want to multiply :" ;
      cin >> n0;
      int i=1;

   while (i<=n0)
        {         cout << num <<" * "<< i << " = "<<num * i << endl;
          i++;

        }
     break;




      default :
      cout << "maybe your text is invalid" << endl<< "Try again !";
        break;
      }

cout << endl<< "Done ! ";
getch ();

}
