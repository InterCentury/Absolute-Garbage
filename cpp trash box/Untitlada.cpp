#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
  char ch;

  cout<< "Enter any character :";

  cin>>ch;

  ch = toupper(ch);

  cout<<"Upper case = "<<ch;

  getch();

}
