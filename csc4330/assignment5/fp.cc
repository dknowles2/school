// Author: dknowles2@gmail.com (David Knowles)

#include <cmath>
#include <iostream>

/**
 * Demonstrates that floating point arithmetic is not associative.
 */
int main()
{
  using namespace std;

  float a = pow(10.0, 30.0);
  float b = -pow(10.0, 30.0);
  float c = 1.0;

  cout << (a + b) + c << endl;
  cout << a + (b + c) << endl;
}
