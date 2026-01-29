#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
  char name;
  cout<< "Enter any text :";

  cin>>name;

  name = toupper(name);

  cout<<"Upper case = "<<name;

  getch();

}
