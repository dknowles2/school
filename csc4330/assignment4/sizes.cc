#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

int main()
{
  struct s1_type {
    long i;  // 8
    char ch; // 1
    int *ip; // 4
  } s1;

  cout << "size: " << sizeof(s1)    << endl;
  cout << "i: "    << sizeof(s1.i)  << endl;
  cout << "ch: "   << sizeof(s1.ch) << endl;
  cout << "ip: "   << sizeof(s1.ip) << endl;
  cout << endl << endl;

  union u_type {
    float f;
    char *cp;
    short s[3];
    double d;
  } u;

  cout << "size: " << sizeof(u) << endl;
  cout << "float: " << sizeof(u.f) << endl;
  u.f = 1.1;
  cout << "size: " << sizeof(u) << endl;


  return 0;
}
