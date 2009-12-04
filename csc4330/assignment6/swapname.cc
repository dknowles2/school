// Author: dknowles2@gmail.com (David Knowles)

#include <iostream>

template <class T>
void myswap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}


int main()
{
  using namespace std;

  int a[2] = {1, 2};
  cout << "Pre-swap:  ";
  cout << "a[0] = " << a[0] << "; a[1] = " << a[1] << endl;

  int i = 0;
  myswap(a[i], a[++i]);
  cout << "Post-swap: ";
  cout << "a[0] = " << a[0] << "; a[1] = " << a[1] << endl;

  int x = 1;
  int y = 2;
  myswap(x, y);
  cout << x << "; " << y << endl;
}
