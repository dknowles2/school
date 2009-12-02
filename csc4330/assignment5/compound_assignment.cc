// Author: dknowles2@gmail.com (David Knowles)

#include <iostream>

int main() {
  using namespace std;

  int i;
  int a[2];

  i = 0;
  a[0] = 3;
  a[1] = 6;
  a[++i] += 2;
  cout << a[1] << endl;

  i = 0;
  a[0] = 3;
  a[1] = 6;
  a[++i] = a[++i] + 2;
  cout << a[1] << endl;
}
