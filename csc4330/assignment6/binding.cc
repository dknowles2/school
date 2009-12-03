// Author: dknowles2@gmail.com (David Knowles)

#include <iostream>

using namespace std;

typedef void (*function)();
int x;

void foo()
{
  cout << x << endl;
}

void bar(function sub)
{
  int x = 3;
  sub();
}

void baz()
{
  int x = 2;
  bar(foo);
}

int main()
{
  x = 1;
  baz();
}
