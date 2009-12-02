// Author: dknowles2@gmail.com (David Knowles)

/*
 * CSC 4330, Fall 2009
 * Assignment 4, Problem 5
 *
 * This will print the binary representation of a
 * given float as a series of 32 bits.
 *
 * For example, the call:
 *
 *   print_float(2.0);
 *
 * will print:
 *
 *   01000000000000000000000000000000
 *
 * When run, this program will prompt the user for
 * a float value that will be printed to the screen
 * as its binary representation.
 */

#include <bitset>
#include <iostream>

using namespace std;


void print_float(float f)
{
  union u_type {
    float f;
    int i;
  } u;
  u.f = f;
  cout << bitset<32>(u.i).to_string() << endl;
}

int main()
{
  float f;
  cout << "Enter a float value: ";
  cin >> f;
  print_float(f);
  cout << endl;
  return 0;
}
