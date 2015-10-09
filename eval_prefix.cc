#include <stdio.h>

const char * a;
int i = 0;

int eval() {
  int x = 0;
  while (a[i] == ' ') i++; // skip white spaces

  if (a[i] == '+') {
    i++;
    return (eval() + eval());
  }
  if (a[i] == '*') {
    i++;
    return (eval() * eval());
  }
  while (a[i] >= '0' && a[i] <= '9')
    x = x*10 + (a[i++] - '0');
  return x;
}

int main() {
  a = "* + 7 * * 4 6 + 8 9 5";
  printf("result: %d\n", eval());
}
