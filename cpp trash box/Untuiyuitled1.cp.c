#include <iostream>
#include <conio.h>
using namespace std;
int main()
{   int n1,n2;
    cout << "For multiplication-table ,    press  $ "<<endl;
    cout << "For Plus                      press  + "<<endl;
    cout << "For Minus                     press  - "<<endl;
    cout << "For Multiplication            press  * "<<endl;
    cout << "For Division                  press  / "<<endl;
    cout << "For marks                     press  & "<<endl<<endl<<endl;
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

   cout << "How many times do you want to multiply ?"<<endl ;
   cout << "Enter times : "  ;
   cin >> n0;
   int i=1;

   while (i<=n0)
{         cout << num <<" * "<< i << " = "<<num * i << endl;
          i++;
}
break;

case '&':
    int marks;
     cout << "Enter your marks : ";
     cin >> marks;
     cout<<endl;

    if (marks >100 )
    {cout << "Invalid marks."<<endl<<endl<<"Please Enter valid marks." ;}


    else if (marks>= 80 )
    {cout << "A+";}

    else if (marks>= 70 )
    {cout << "A";}

    else if (marks>= 60 )
   {cout << "A-";}

    else if (marks>= 50 )
    {cout << "B";}

    else if (marks>= 40 )
    {cout << "C";}

    else if (marks>= 33 )
    {cout << "D";}

    else {cout << "Fail"<<endl<< "Better lick next time !";};

      }
cout << endl<<endl<<endl<< "Done ! ";
getch ();

}
