#include <stdio.h>
#include <algorithm>

// Greatest Common Divider

int gcd (int i, int j) {
  int done = 0;
  while (!done) {
    if (i < j) {
      std::swap (i, j);
    }
    else if (j != 0) {
      i = i - j;
    }
    else
      done = 1;
  }
  return i;
}

int main() {
  int i = 12;
  int j = 9;
  printf("The GCD of %d %d is %d\n", i, j, gcd(i, j));
  return 0;
}
