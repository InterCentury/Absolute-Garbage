#include       <iostream>
#include       <conio.h>

using namespace std;

int main()
{ char ch;
  cout<< "Enter any character :";
  cin>>ch;

  ch = tolower(ch); 
  //   if input "A"then it will be
  //   automatic convart to "a"(small letter)
  if (ch=='a' 
   || ch=='e' 
   || ch=='i'
   || ch=='o'
   || ch=='u')
  // || ch=='A'
  // || ch=='E'
  // || ch=='I'
  // || ch=='O'
  // || ch=='U')
  {cout<<"vowel";}
  else  {cout<<"consonant";}
  getch();


}


