#include <iostream>
#include <conio.h>

using namespace std ;

int main ()
{
  char ch;
  cout << "Enter any character :" ;
  cin  >> ch;

  ch = tolower (ch);

  switch (ch)
{
  case 'a':

  case 'e':

  case 'i':

  case 'o':

  case 'u':

       cout << ch << " is vowel.";
       break;

 default:
       cout <<ch<< " is consonant" ;
}
   getch();

}
