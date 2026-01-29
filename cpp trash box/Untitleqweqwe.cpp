#include                      <iostream>
#include                      <conio.h>
using namespace std;

int main()
{

  int year ;


  cout << "Enter year :";

  cin >> year;

      if (year  %4 ==0  && year  %100!= 0)
         {

         cout<< "leapyear";

         }

else if (year%4==0)
        {

        cout<< "Leapyear";

        }

else {

    cout  <<   "Not Leapyear";

     }


     getch();

}
