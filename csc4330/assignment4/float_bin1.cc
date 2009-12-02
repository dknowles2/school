// Author: dknowles2@gmail.com (David Knowles)

#include <bitset>
#include <cassert>
#include <iostream>

using namespace std;


string float_to_bin(float f)
{
  union u_type {
    float f;
    int i;
  } u;
  u.f = f;
  return bitset<32>(u.i).to_string();
}


void print_float(float f)
{
  cout << float_to_bin(f) << endl;
}


/**
 * Runs tests for known conversions.
 */
void run_tests()
{
  // Wikipedia example:
  assert(float_to_bin(-118.625) == "11000010111011010100000000000000");

  // From the assignment:
  assert(float_to_bin(2.0) == "01000000000000000000000000000000");

  // Mutation from assignment:
  assert(float_to_bin(-2.0) == "11000000000000000000000000000000");
}


int main()
{
  run_tests();

  while (true) {
    float f;
    cout << "Enter a float value: ";
    cin >> f;
    print_float(f);
    cout << endl;
  }

  return 0;
}
