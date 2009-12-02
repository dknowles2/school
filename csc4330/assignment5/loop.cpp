#include <iostream>

int main() {
  using namespace std;
  int n = 20;
  int j = 0;
  for (int i = 1; i <= n; i += 2) {
    j += i;
    cout << j << endl;
  }
}
