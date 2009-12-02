// Author: dknowles2@gmail.com (David Knowles)

#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


const int BIAS = 127;
const int MAX_BITS = 32;
const int FRACTION_BITS = 23;
const int EXPONENT_BITS = 8;
const int SIGN_BITS = 1;

typedef bitset<MAX_BITS> ieee754_32;


/**
 * Converts a decimal point into binary.
 *
 * Warning: This function has side effects.
 *
 * bs is modified by this function.
 *
 * Args:
 *   bs: ieee754_32, bitset container for the ieee754 conversion.
 *   decimal_pt: int, bit to start at in bs.
 *   n: float, decimal portion of a float to convert to binary.
 */
void convert_dec(ieee754_32 *bs, int decimal_pt, float n)
{
  if (n == 0.0) {
    return;
  }

  while (n > 0 && decimal_pt > 0) {
    n = n * 2;
    int val = (n >= 1) ? true : false;
    (*bs)[decimal_pt] = val;

    if (n >= 1) {
      n = n - 1.0;
    }
    decimal_pt--;
  }
}


/**
 * Converts a float into its ieee754_32 binary format.
 *
 * Args:
 *   f: float, Float to convert
 * Returns:
 *   string, ieee754_32 binary format for the float.
 */
string float_to_bin(float f)
{
  int int_part = floor(fabs(f));
  float dec_part = fabs(f) - int_part;
  bool sign_bit = f < 0;
  ieee754_32 bs(int_part);

  // Find the most significant bit so we know how much to shift.
  size_t decimal_pt = bs.to_string().find_first_not_of('0');
  decimal_pt = (decimal_pt == string::npos) ? 0 : decimal_pt;

  // Shift the bits to a left-padded fraction.
  bs = bs << ( decimal_pt - EXPONENT_BITS);
  bs[FRACTION_BITS] = 0;

  // Add the decimal conversion.
  convert_dec(&bs, FRACTION_BITS - (MAX_BITS - decimal_pt), dec_part);

  // Add the sign bit
  bs[MAX_BITS - 1] = sign_bit;

  // Exponent calculation
  int int_exp = BIAS + MAX_BITS - decimal_pt - 1;
  ieee754_32 exponent(int_exp);
  exponent = exponent << (MAX_BITS - EXPONENT_BITS - 1);
  bs = bs |= exponent;

  return bs.to_string();
}


/**
 * Prints the ieee754_32 binary format for a float.
 */
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
