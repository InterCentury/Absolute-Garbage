#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
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
      {

        case '+' :
       {int n1,n2;
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
      }

case '$':
   { int num =1,0;
    cout << "For low to high    press 0"<<endl;
    cout << "For high to low    press 1"<<endl;
    cout << "Enter key : ";
  cin>>num;


if (num=0)
{  int n1,n2;
    cout << "Enter number : ";
    cin >>n1;

    cout<< "start from : ";
    cin >>n2;

int i =n2;
  do{
       cout <<n1<<"*"<<i<<"="<<n1*i<<endl;
       i--;
    } while (i>=n1);


}

else if(num = 1)

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



}

break;}

case '&':
   { int marks;
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
   break;}

   default :
   {

    cout <<endl<< "Please enter valid operator !";}

    }

cout << endl<<endl<<endl<< "Done ! ";
getch ();

}
