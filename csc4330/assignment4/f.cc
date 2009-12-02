#include <iostream>

using namespace std;

void f(char *p)
{
  char *q = p;

  while (*q)
    q++;

  while (p < q) {
    char ch = *p;
    *p++ = *--q;
    *q = ch;
  }
}

int main() {
  char s[] = "Hello world";
  f(s);
  cout << s << endl;
}
