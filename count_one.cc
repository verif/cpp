#include <stdio.h>

int count_one(int n) {
  int cnt = 0;
  while (n) {
    n &= (n-1);
    cnt++;
  }
  return cnt;
}

int main () {
  printf("number of 1's of 5: %d\n", count_one(5));
  printf("number of 1's of 7: %d\n", count_one(7));
  return 0;
}
