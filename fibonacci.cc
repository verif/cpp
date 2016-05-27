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

void gen_fibonacci2(int level) {
  int i = 1;
  int j = 1;
  int cnt = 0;
  while (cnt < level) {
    cout << i << endl;
    int tmp = j;
    j = i + j;
    i = tmp;
    cnt++;
  }
}
  
int main() {
  for (int i = 0; i < 12; i++) {
    cout << gen_fibonacci(i) << endl;
  }
  gen_fibonacci2(12);
  return 0;
}
