#include <iostream>
#include <conio.h>

using namespace std;

int main() {

int marks;

cout << "Enter your marks :";
cin >> marks;

if (marks >32)
{ if      (marks >=80 ) {cout << "A+ ";

}else if  (marks >=70 ) {cout << "A ";

}else if  (marks >=60 ) {cout << "A-" ;

}else if  (marks >=50 ) {cout << "B ";

}else if  (marks >=40 ) {cout << "C";

}else if  (marks >=33 ) {cout << "D";

}

}else {cout << "Fail"<< endl<< "Better luck next time";}
}
