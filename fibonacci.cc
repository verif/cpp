#include <stdio.h>
#include <iostream>

using namespace std;

int gen_fibonacci(int level) {
  int i, j;
  i = 0;
  j = 1;
  while (level > 0) {
    int tmp = j;
    j = i + j;
    i = tmp;
    level--;
  }
  return j;
}
  
int main() {
  for (int i = 0; i < 12; i++) {
    cout << gen_fibonacci(i) << endl;
  }
  return 0;
}
