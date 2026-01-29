#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
   int mark;
   cout<<"Enter your mark :";
   cin>>mark;



if (mark > 100)          {cout<<"invalid mark "; }

else (mark < 0)          {cout<<"invalid mark "; }

else (mark >= 80)        {cout<<"A+";            }

else (mark >= 70)        {cout<<"A";             }

else (mark >= 60)        {cout<<"A-";            }

else (mark >= 50)        {cout<<"B";             }

else (mark >= 40)        {cout<<"D";             }

else (mark >= 33)        {cout<<"E";             }

else                     {cout<<"fail"endl;
                    cout<<"better luck next time"; }


getch();


}
